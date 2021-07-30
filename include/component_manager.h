#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <stdint.h>
#include <dats/dats.h>

#include "entity.h"
#include "component.h"

typedef struct
{
    // probably use a bst or hashmap for O(logn) at least
    dats_dynamic_array_t component_descs;
    dats_dynamic_array_t component_array;
    uint64_t number_of_component_variation;
} ents_component_manager_t;

ents_component_manager_t ents_component_manager_new();

uint64_t ents_component_manager_register(ents_component_manager_t *self, ents_component_desc_t *component_desc);

void ents_component_manager_set(ents_component_manager_t *self, ents_entity_t entity, uint64_t component_type, const void *data);

const void *ents_component_manager_get(const ents_component_manager_t *self, ents_entity_t entity, uint64_t component_type);

void *ents_component_manager_ref(ents_component_manager_t *self, ents_entity_t entity, uint64_t component_type);

void ents_component_manager_remove(ents_component_manager_t *self, ents_entity_t entity, uint64_t component_type);

uint64_t ents_component_manager_get_id_from_name(const ents_component_manager_t *self, const char *name);

void ents_component_manager_print(const ents_component_manager_t *self);

void ents_component_manager_clear(ents_component_manager_t *self);

void ents_component_manager_free(ents_component_manager_t *self);

#endif