#include <dats/dynamic_array.h>
#include <dats/queue.h>
#include <stdint.h>
#include <stdlib.h>

#include "entity_manager.h"
#include "type.h"

ents_entity_manager_t ents_entity_manager_new()
{
    ents_entity_manager_t em = {
        .next_higher_available_id = 0,
        .available_ids = dats_queue_new(sizeof(uint64_t)),
        .entity_type = dats_dynamic_array_new(4, sizeof(ents_type_t)),
    };

    return em;
}

ents_entity_t ents_entity_manager_create_entity(ents_entity_manager_t *self)
{
    if (dats_queue_length(&self->available_ids) > 0)
    {
        uint64_t *available_id = dats_queue_dequeue(&self->available_ids);
        ents_entity_t e = {
            .id = *available_id
        };
        free(available_id);
        return e;
    }
    else
    {
        ents_entity_t e = {
            .id = self->next_higher_available_id
        };
        self->next_higher_available_id++;

        ents_type_t type = ents_type_new();
        dats_dynamic_array_add(&self->entity_type, &type);

        return e;
    }
}

void ents_entity_manager_free(ents_entity_manager_t *self)
{
    for (uint64_t i = 0; i < dats_dynamic_array_length(&self->entity_type); i++)
    {
        ents_type_t *type = dats_dynamic_array_ref(&self->entity_type, i);
        ents_type_free(type);
    }
    dats_dynamic_array_free(&self->entity_type);
    dats_queue_free(&self->available_ids);
}
