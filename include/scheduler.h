#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <dats/dats.h>

#include "system.h"
#include "world.h"

typedef struct
{
    dats_dynamic_array_t systems;
} ents_scheduler_t;

ents_scheduler_t ents_scheduler_new();

void ents_scheduler_system_add(ents_scheduler_t *self, const ents_world_t *world, ents_system_t *system);

void ents_scheduler_execute(ents_scheduler_t *self, ents_world_t *world);

void ents_scheduler_print(const ents_scheduler_t *self);

void ents_scheduler_free(ents_scheduler_t *self);

#endif