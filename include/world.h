#ifndef WORLD_H
#define WORLD_H

#include "entity_manager.h"
#include "component_manager.h"
#include <stdint.h>

typedef struct
{
    ents_entity_manager_t em;
    ents_component_manager_t cm;
} ents_world_t;

ents_world_t ents_world_new();

ents_component_type_t ents_world_component_register(ents_world_t *self, ents_component_desc_t *desc);

void ents_world_free(ents_world_t *self);

#endif