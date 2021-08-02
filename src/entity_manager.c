#include "entity_manager.h"
#include <dats/dynamic_array.h>

#include "type.h"

ents_entity_manager_t ents_entity_manager_new()
{
    ents_entity_manager_t em = {
        .entity_type = dats_dynamic_array_new(4, sizeof(ents_type_t))
    };

    return em;
}

void ents_entity_manager_free(ents_entity_manager_t * self)
{
    dats_dynamic_array_free(&self->entity_type);
}
