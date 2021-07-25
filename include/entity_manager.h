#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <stdint.h>

#include <dats/dats.h>

#include "entity.h"

typedef struct
{
    dats_queue_t available_ids;
    uint64_t next_higher_available_id;
} ents_entity_manager_t;

ents_entity_manager_t ents_entity_manager_new();

ents_entity_t ents_entity_manager_create_entity(ents_entity_manager_t *self);

void ents_entity_manager_destroy_entity(ents_entity_manager_t *self, ents_entity_t entity);

void ents_entity_manager_free(ents_entity_manager_t *self);

#endif