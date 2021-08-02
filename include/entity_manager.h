#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <stdint.h>
#include <stdbool.h>

#include <dats/dats.h>

#include "entity.h"

typedef struct
{
    dats_queue_t available_ids;
    uint64_t next_higher_available_id;
    dats_dynamic_array_t entity_record;
} ents_entity_manager_t;

ents_entity_manager_t ents_entity_manager_new();

ents_entity_t ents_entity_manager_entity_create(ents_entity_manager_t *self);

// void ents_entity_manager_entity_set_component(ents_entity_manager_t *self, ents_entity_t entity, uint64_t component_type);

// void ents_entity_manager_entity_remove_component(ents_entity_manager_t *self, ents_entity_t entity, uint64_t component_type);

// bool ents_entity_manager_entity_has_component(const ents_entity_manager_t *self, ents_entity_t entity, uint64_t component_type);

void ents_entity_manager_entity_destroy(ents_entity_manager_t *self, ents_entity_t entity);

void ents_entity_manager_print(const ents_entity_manager_t *self);

void ents_entity_manager_free(ents_entity_manager_t *self);

#endif