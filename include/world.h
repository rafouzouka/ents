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

ents_entity_t ents_world_create_entity(ents_world_t *self);

void ents_world_destroy_entity(ents_world_t *self, ents_entity_t entity);

uint64_t ents_world_register_component(ents_world_t *self, uint64_t data_size);

void ents_world_set_component(ents_world_t *self, ents_entity_t entity, uint64_t component_type, const void *data);

const void *ents_world_get_component(const ents_world_t *self, ents_entity_t entity, uint64_t component_type);

void *ents_world_ref_component(ents_world_t *self, ents_entity_t entity, uint64_t component_type);

void ents_world_remove_component(ents_world_t *self, ents_entity_t entity, uint64_t component_type);

void ents_world_print(const ents_world_t *self);

void ents_world_free(ents_world_t *self);

#endif