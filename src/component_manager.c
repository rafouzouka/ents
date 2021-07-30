#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dats/dats.h>

#include "component_manager.h"

ents_component_manager_t ents_component_manager_new()
{
    ents_component_manager_t cm = {
        .component_descs = dats_dynamic_array_new(4, sizeof(ents_component_desc_t)),
        .component_array = dats_dynamic_array_new(4, sizeof(dats_dense_array_t)),
        .number_of_component_variation = 0
    };

    return cm;
}

uint64_t ents_component_manager_register(ents_component_manager_t *self, ents_component_desc_t *component_desc)
{
    dats_dynamic_array_add(&self->component_descs, component_desc);
    dats_dense_array_t da = dats_dense_array_new(component_desc->data_size);

    dats_dynamic_array_add(&self->component_array, &da);
    self->number_of_component_variation++;
    return self->number_of_component_variation - 1;
}

void ents_component_manager_set(ents_component_manager_t *self, ents_entity_t entity, uint64_t component_type, const void *data)
{
    dats_dense_array_t *dense_array = dats_dynamic_array_ref(&self->component_array, component_type);
    dats_dense_array_insert(dense_array, entity.id, data);
}

const void *ents_component_manager_get(const ents_component_manager_t *self, ents_entity_t entity, uint64_t component_type)
{
    const dats_dense_array_t *dense_array = dats_dynamic_array_get(&self->component_array, component_type);
    return dats_dense_array_get(dense_array, entity.id);
}

void *ents_component_manager_ref(ents_component_manager_t *self, ents_entity_t entity, uint64_t component_type)
{
    dats_dense_array_t *dense_array = dats_dynamic_array_ref(&self->component_array, component_type);
    return dats_dense_array_ref(dense_array, entity.id);
}

void ents_component_manager_remove(ents_component_manager_t *self, ents_entity_t entity, uint64_t component_type)
{
    dats_dense_array_t *da = dats_dynamic_array_ref(&self->component_array, component_type);
    dats_dense_array_remove(da, entity.id);
}

uint64_t ents_component_manager_get_id_from_name(const ents_component_manager_t *self, const char *name)
{
    for (uint64_t i = 0; i < dats_dynamic_array_length(&self->component_descs); i++)
    {
        const ents_component_desc_t *component_desc = dats_dynamic_array_get(&self->component_descs, i);
        if (strcmp(component_desc->name, name) == 0)
        {
            return i;
        }
    }
    exit(-1);
}

void ents_component_manager_print(const ents_component_manager_t *self)
{
    printf("---- COMPONENTS: ----\n");
    for (uint64_t i = 0; i < self->number_of_component_variation; i++)
    {
        const dats_dense_array_t *da = dats_dynamic_array_get(&self->component_array, i);
        
        const ents_component_desc_t *component_dest = dats_dynamic_array_get(&self->component_descs, i);

        printf("%s %ld :\n", component_dest->name, i);
        uint64_t length = da->data_length;
        if (length == 0)
        {
            printf("EMPTY");
        } 
        else 
        {
            for (uint64_t j = 0; j < length; j++)
            {
                printf("[ITEM] ");
            }
        }
        printf("\n\n");
    }
}

void ents_component_manager_clear(ents_component_manager_t *self)
{
    for (uint64_t i = 0; i < self->number_of_component_variation; i++)
    {
        dats_dense_array_t *da = dats_dynamic_array_ref(&self->component_array, i);
        dats_dense_array_clear(da);
    }
}

void ents_component_manager_free(ents_component_manager_t *self)
{
    for (uint64_t i = 0; i < self->number_of_component_variation; i++)
    {
        dats_dense_array_t *da = dats_dynamic_array_ref(&self->component_array, i);
        dats_dense_array_free(da);
    }

    dats_dynamic_array_free(&self->component_descs);
    dats_dynamic_array_free(&self->component_array);
    self->number_of_component_variation = 0;
}
