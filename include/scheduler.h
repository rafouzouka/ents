#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <dats/dats.h>

#include "system.h"

typedef struct
{
    dats_dynamic_array_t systems;
} ents_scheduler_t;

ents_scheduler_t ents_scheduler_new();

void ents_scheduler_add_system(ents_scheduler_t *self, ents_system_t *data);

void ents_scheduler_execute(ents_scheduler_t *self);

void ents_scheduler_print(const ents_scheduler_t *self);

void ents_scheduler_free(ents_scheduler_t *self);

#endif