#include <dats/bitset.h>
#include <dats/dynamic_array.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "system.h"

static uint64_t _tokenize_query_to_bitset(ents_system_t *system, const ents_world_t *world)
{
    system->bitset = dats_bitset_new(world->cm.number_of_component_variation);

    char *str = malloc(sizeof(char) * strlen(system->query) + 1);
    strcpy(str, system->query);

    uint64_t number_of_components = 0;
    dats_dynamic_array_t component_types = dats_dynamic_array_new(1, sizeof(uint64_t));

    char *token = strtok(str, ", ");
    while (token != NULL)
    {
        uint64_t id = ents_component_manager_get_id_from_name(&world->cm, token);
        dats_dynamic_array_add(&component_types, &id);
        dats_bitset_set(&system->bitset, id + 1, true);
        number_of_components++;

        token = strtok(NULL, ", ");
    }

    system->component_types = component_types;
    free(str);
    return number_of_components;
}

void ents_system_fill(ents_system_t *pre_filled_system, const ents_world_t *world)
{
    uint64_t number_of_components = _tokenize_query_to_bitset(pre_filled_system, world);

    pre_filled_system->params = (ents_params_t){
        .number_of_params = number_of_components,
        .array = dats_dynamic_array_new(number_of_components, sizeof(ents_param_t)),
    };

    for (uint64_t i = 0; i < number_of_components; i++)
    {
        dats_dynamic_array_add(&pre_filled_system->params.array, &(ents_param_t) { .component = NULL });
    }
}

void ents_system_print(const ents_system_t *self)
{    
    printf("%s([", self->name);

    for (uint64_t i = 0; i < self->params.number_of_params; i++)
    {
        const uint64_t *component_type = dats_dynamic_array_get(&self->component_types, i);
        if (i == self->params.number_of_params - 1)
        {
            printf("%ld", *component_type);
        }
        else
        {
            printf("%ld, ", *component_type);
        }
    }

    printf("]): %s ", self->query);

    dats_bitset_print(&self->bitset);
    printf("\n");
}

void ents_system_free(ents_system_t *self)
{
    dats_dynamic_array_free(&self->component_types);
    dats_dynamic_array_free(&self->params.array);
    dats_bitset_free(&self->bitset);   
}

void *ents_params_ref(ents_params_t *self, uint64_t position)
{
    ents_param_t *param = dats_dynamic_array_ref(&self->array, position-1);
    return param->component;
}

const void *ents_params_get(const ents_params_t *self, uint64_t position)
{
    const ents_param_t *param = dats_dynamic_array_get(&self->array, position-1);
    return param->component;
}

