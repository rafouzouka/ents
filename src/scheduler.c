#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <dats/dats.h>

#include "scheduler.h"

ents_scheduler_t ents_scheduler_new()
{
    ents_scheduler_t scheduler = {
        .systems = dats_dynamic_array_new(4, sizeof(ents_system_t)),
    };

    return scheduler;
}

void ents_scheduler_system_add(ents_scheduler_t *self, const ents_world_t *world, ents_system_t *system)
{
    system->bitset = dats_bitset_new(world->cm.number_of_component_variation);

    char *str = malloc(sizeof(char) * strlen(system->query) + 1);
    strcpy(str, system->query);

    char *token = strtok(str, ", ");
    while (token != NULL)
    {
        uint64_t id = ents_component_manager_get_id_from_name(&world->cm, token);
        dats_bitset_set(&system->bitset, id + 1, true);

        token = strtok(NULL, ", ");
    }

    free(str);
    dats_dynamic_array_add(&self->systems, system);
}

// void ents_scheduler_execute(ents_scheduler_t *self, ents_world_t *world)
// {
//     for (uint64_t i = 0; i < dats_dynamic_array_length(&self->systems); i++)
//     {
//         ents_system_t *system = dats_dynamic_array_ref(&self->systems, i);
//         system->callback(system->name);
//     }
// }

void ents_scheduler_print(const ents_scheduler_t *self)
{
    printf("---- SYSTEMS: ----\n");
    for (uint64_t i = 0; i < dats_dynamic_array_length(&self->systems); i++)
    {
        const ents_system_t *system = dats_dynamic_array_get(&self->systems, i);        
        printf("[%s] -> %s : ", system->name, system->query);
        dats_bitset_print(&system->bitset);
        printf("\n");
    }    
}

void ents_scheduler_free(ents_scheduler_t *self)
{
    for (uint64_t i = 0; i < dats_dynamic_array_length(&self->systems); i++)
    {
        ents_system_t *system = dats_dynamic_array_ref(&self->systems, i);        
        dats_bitset_free(&system->bitset);
    }    

    dats_dynamic_array_free(&self->systems);
}
