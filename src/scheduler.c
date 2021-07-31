#include <dats/bitset.h>
#include <dats/dynamic_array.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <dats/dats.h>

#include "scheduler.h"
#include "entity_manager.h"
#include "system.h"

ents_scheduler_t ents_scheduler_new()
{
    ents_scheduler_t scheduler = {
        .systems = dats_dynamic_array_new(4, sizeof(ents_system_t)),
    };

    return scheduler;
}

void ents_scheduler_system_add(ents_scheduler_t *self, const ents_world_t *world, ents_system_t *system)
{
    ents_system_fill(system, world);
    dats_dynamic_array_add(&self->systems, system);
}

void ents_scheduler_execute(ents_scheduler_t *self, ents_world_t *world)
{
    ents_entity_t entity = { .id = 0 };
    
    for (uint64_t i = 0; i < dats_dynamic_array_length(&self->systems); i++)
    {
        ents_system_t *system = dats_dynamic_array_ref(&self->systems, i);

        for (uint64_t entity_id = 0; entity_id < dats_dynamic_array_length(&world->em.bitsets); entity_id++)
        {
            const dats_bitset_t *entity_bitset = dats_dynamic_array_get(&world->em.bitsets, entity_id);

            if (dats_bitset_is_set_bitset(entity_bitset, &system->bitset) == true)
            {
                entity.id = entity_id;

                for (uint64_t j = 0; j < dats_dynamic_array_length(&system->component_types); j++)
                {
                    const uint64_t *component_type = dats_dynamic_array_get(&system->component_types, j);
                    void *component = ents_component_manager_ref(&world->cm, entity, *component_type);

                    ents_param_t *param = dats_dynamic_array_ref(&system->params.array, j);
                    param->component = component;
                }                

                system->callback(&system->params);
            }
        }
    }
}

void ents_scheduler_print(const ents_scheduler_t *self)
{
    printf("---- SYSTEMS: ----\n");
    for (uint64_t i = 0; i < dats_dynamic_array_length(&self->systems); i++)
    {
        const ents_system_t *system = dats_dynamic_array_get(&self->systems, i);        
        ents_system_print(system);
    }    
}

void ents_scheduler_free(ents_scheduler_t *self)
{
    for (uint64_t i = 0; i < dats_dynamic_array_length(&self->systems); i++)
    {
        ents_system_t *system = dats_dynamic_array_ref(&self->systems, i);        
        ents_system_free(system);
    }    

    dats_dynamic_array_free(&self->systems);
}
