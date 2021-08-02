#include "world.h"
#include "component_manager.h"

ents_world_t ents_world_new()
{
    ents_world_t world = {
        .em = ents_entity_manager_new(),
        .cm = ents_component_manager_new(),
    };

    return world;
}

ents_component_type_t ents_world_component_register(ents_world_t *self, ents_component_desc_t *desc)
{
    return ents_component_manager_component_register(&self->cm, desc);
}

void ents_world_free(ents_world_t *self)
{
    ents_entity_manager_free(&self->em);
    ents_component_manager_free(&self->cm);
}
