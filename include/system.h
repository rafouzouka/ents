#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdint.h>

#include <dats/dats.h>

#include "world.h"

typedef struct
{
    void *component;
} ents_param_t;

typedef struct
{
    uint64_t number_of_params;
    dats_dynamic_array_t array;
} ents_params_t;

typedef struct
{
    const char *name;
    const char *query;
    dats_bitset_t bitset;
    dats_dynamic_array_t component_types;
    ents_params_t params;
    void (*callback)(ents_params_t *params);
} ents_system_t;

void ents_system_fill(ents_system_t *pre_filled_system, const ents_world_t *world);

void ents_system_print(const ents_system_t *self);

void ents_system_free(ents_system_t *self);

void *ents_params_ref(ents_params_t *self, uint64_t position);

const void *ents_params_get(const ents_params_t *self, uint64_t position);

#endif