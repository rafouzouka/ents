#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <dats/dynamic_array.h>
#include <stdint.h>

#include <dats/dats.h>

#include "entity.h"

typedef struct
{
    dats_queue_t available_ids;
    dats_dynamic_array_t bitsets;
    uint64_t bitset_size;
    uint64_t next_higher_available_id;
} ents_entity_manager_t;

ents_entity_manager_t ents_entity_manager_new();

ents_entity_t ents_entity_manager_create_entity(ents_entity_manager_t *self);

void ents_entity_manager_destroy_entity(ents_entity_manager_t *self, ents_entity_t entity);

void ents_entity_manager_set_bitset_size(ents_entity_manager_t *self, uint64_t bitset_size);

void ents_entity_manager_set(ents_entity_manager_t *self, ents_entity_t entity, uint64_t component_type);

void ents_entity_manager_remove(ents_entity_manager_t *self, ents_entity_t entity, uint64_t component_type);

const void *ents_entity_manager_get_bitset(const ents_entity_manager_t *self, ents_entity_t entity);

void ents_entity_manager_print(const ents_entity_manager_t *self);

void ents_entity_manager_free(ents_entity_manager_t *self);

#endif