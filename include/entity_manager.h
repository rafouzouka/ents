#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <dats/dats.h>

typedef struct
{
    dats_dynamic_array_t entity_type;
} ents_entity_manager_t;

ents_entity_manager_t ents_entity_manager_new();

void ents_entity_manager_free(ents_entity_manager_t * self);

#endif