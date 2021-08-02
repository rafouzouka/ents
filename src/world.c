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

void ents_world_free(ents_world_t *self)
{
    ents_entity_manager_free(&self->em);
    ents_component_manager_free(&self->cm);
}
