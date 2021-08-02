#ifndef TYPE_H
#define TYPE_H

#include <stdint.h>
#include <stdbool.h>

#include <dats/dats.h>

typedef struct
{
    dats_dynamic_array_t component_ids;
} ents_type_t;

ents_type_t ents_type_new();

void ents_type_add(ents_type_t *self, uint64_t component_type);

void ents_type_remove(ents_type_t *self, uint64_t component_type);

bool ents_type_has(const ents_type_t *self, uint64_t component_type);

void ents_type_clear(ents_type_t *self);

ents_type_t ents_type_clone(const ents_type_t *self);

void ents_type_print(const ents_type_t *self);

void ents_type_free(ents_type_t *self);

#endif