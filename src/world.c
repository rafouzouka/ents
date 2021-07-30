#include <dats/bitset.h>
#include <stdint.h>

#include "scheduler.h"
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
    const dats_bitset_t *bitset = ents_entity_manager_get_bitset(&self->em, entity);

    for (uint64_t i = 0; i < bitset->size; i++)
    {
        if (dats_bitset_is_set(bitset, i+1) == true)
        {
            ents_component_manager_remove(&self->cm, entity, i);
        }
    }

    ents_entity_manager_destroy_entity(&self->em, entity);
}

uint64_t ents_world_register_component(ents_world_t *self, ents_component_desc_t *component_desc)
{
    uint64_t component_id = ents_component_manager_register(&self->cm, component_desc);
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

void ents_world_remove_component(ents_world_t *self, ents_entity_t entity, uint64_t component_type)
{
    ents_entity_manager_remove(&self->em, entity, component_type);
    ents_component_manager_remove(&self->cm, entity, component_type);
}

void ents_world_add_system(ents_world_t *self, ents_system_t *system)
{
    ents_scheduler_add_system(&self->sh, system);
}

void ents_world_print(const ents_world_t *self)
{
    ents_entity_manager_print(&self->em);
    ents_component_manager_print(&self->cm);
}

void ents_world_clear(ents_world_t *self)
{   
    ents_entity_manager_clear(&self->em);
    ents_component_manager_clear(&self->cm);
}

void ents_world_free(ents_world_t *self)
{
    ents_entity_manager_free(&self->em);
    ents_component_manager_free(&self->cm);
    ents_scheduler_free(&self->sh);
}
