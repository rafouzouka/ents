#ifndef TYPE_H
#define TYPE_H

#include <dats/dats.h>

typedef struct
{
    dats_dynamic_array_t component_ids;
} ents_type_t;

ents_type_t ents_type_new();

void ents_type_free(ents_type_t *self);

#endif