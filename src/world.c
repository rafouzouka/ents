#include "world.h"
#include "component_manager.h"
#include "entity_manager.h"

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

void ents_world_register(ents_world_t *self, uint64_t data_size)
{
    ents_component_manager_register(&self->cm, data_size);
}

void ents_world_set(ents_world_t *self, ents_entity_t entity, uint64_t component_type, const void *data)
{
    ents_component_manager_set(&self->cm, entity, component_type, data);
}

const void *ents_world_get(const ents_world_t *self, ents_entity_t entity, uint64_t component_type)
{
    return ents_component_manager_get(&self->cm, entity, component_type);
}

void *ents_world_ref(ents_world_t *self, ents_entity_t entity, uint64_t component_type)
{
    return ents_component_manager_ref(&self->cm, entity, component_type);
}

void ents_world_print(const ents_world_t *self)
{
    ents_component_manager_print(&self->cm);
}

void ents_world_free(ents_world_t *self)
{
    ents_entity_manager_free(&self->em);
    ents_component_manager_free(&self->cm);
}
