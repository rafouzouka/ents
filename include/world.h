#ifndef WORLD_H
#define WORLD_H

#include <stdint.h>

#include "entity_manager.h"
#include "component_manager.h"

typedef struct
{
    ents_entity_manager_t em;
    ents_component_manager_t cm;
} ents_world_t;

ents_world_t ents_world_new();

ents_entity_t ents_world_entity_create(ents_world_t *self);

void ents_world_entity_destroy(ents_world_t *self, ents_entity_t entity);

uint64_t ents_world_component_register(ents_world_t *self, ents_component_desc_t *component_desc);

void ents_world_component_set(ents_world_t *self, ents_entity_t entity, uint64_t component_type, const void *data);

const void *ents_world_component_get(const ents_world_t *self, ents_entity_t entity, uint64_t component_type);

void *ents_world_component_ref(ents_world_t *self, ents_entity_t entity, uint64_t component_type);

void ents_world_component_remove(ents_world_t *self, ents_entity_t entity, uint64_t component_type);

void ents_world_print(const ents_world_t *self);

void ents_world_clear(ents_world_t *self);

void ents_world_free(ents_world_t *self);

#endif