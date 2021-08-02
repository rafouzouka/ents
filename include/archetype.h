#ifndef ARCHETYPE_H
#define ARCHETYPE_H

#include <dats/dynamic_array.h>
#include <stdint.h>

#include <dats/dats.h>

#include "type.h"

typedef struct
{
    ents_type_t type;
    dats_dynamic_array_t entity_ids;
    dats_dynamic_array_t chunck_components;
} ents_archetype_t;

ents_archetype_t ents_archetype_new(const ents_type_t *type);

void ents_archetype_free(ents_archetype_t *self);

#endif