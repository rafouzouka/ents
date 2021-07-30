#include <dats/bitset.h>
#include <dats/dynamic_array.h>
#include <stdint.h>
#include <stdio.h>

#include "scheduler.h"

ents_scheduler_t ents_scheduler_new()
{
    ents_scheduler_t scheduler = {
        .systems = dats_dynamic_array_new(4, sizeof(ents_system_t))
    };

    return scheduler;
}

void ents_scheduler_build_system()
{
    
}

void ents_scheduler_add_system(ents_scheduler_t *self, ents_system_t *system)
{
    printf("QUERY: %s\n", system->query);
    dats_dynamic_array_add(&self->systems, system);
}

void ents_scheduler_execute(ents_scheduler_t *self)
{
    for (uint64_t i = 0; i < dats_dynamic_array_length(&self->systems); i++)
    {
        ents_system_t *system = dats_dynamic_array_ref(&self->systems, i);
        // dats_bitset_print(&system->bitset);
        system->callback();
    }
}

void ents_scheduler_free(ents_scheduler_t *self)
{
    dats_dynamic_array_free(&self->systems);
}
