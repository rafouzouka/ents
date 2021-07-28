#include "world.h"
#include "component_manager.h"
#include "entity_manager.h"
#include <stdint.h>

ents_world_t ents_world_new()
{
    ents_world_t world = {
        .em = ents_entity_manager_new(),
        .cm = ents_component_manager_new()
    };

    return world;
}

ents_entity_t ents_world_create_entity(ents_world_t *self)
{
    return ents_entity_manager_create_entity(&self->em);
}

void ents_world_destroy_entity(ents_world_t *self, ents_entity_t entity)
{
    ents_entity_manager_destroy_entity(&self->em, entity);
}

uint64_t ents_world_register_component(ents_world_t *self, uint64_t data_size)
{
    uint64_t component_id = ents_component_manager_register(&self->cm, data_size);
    ents_entity_manager_set_bitset_size(&self->em, component_id + 1);

    return component_id;
}

void ents_world_set_component(ents_world_t *self, ents_entity_t entity, uint64_t component_type, const void *data)
{
    ents_entity_manager_set(&self->em, entity, component_type);
    ents_component_manager_set(&self->cm, entity, component_type, data);
}

const void *ents_world_get_component(const ents_world_t *self, ents_entity_t entity, uint64_t component_type)
{
    return ents_component_manager_get(&self->cm, entity, component_type);
}

void *ents_world_ref_component(ents_world_t *self, ents_entity_t entity, uint64_t component_type)
{
    return ents_component_manager_ref(&self->cm, entity, component_type);
}

void ents_world_print(const ents_world_t *self)
{
    ents_entity_manager_print(&self->em);
    ents_component_manager_print(&self->cm);
}

void ents_world_free(ents_world_t *self)
{
    ents_entity_manager_free(&self->em);
    ents_component_manager_free(&self->cm);
}
