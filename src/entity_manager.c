#include <stdint.h>
#include <stdlib.h>

#include <dats/queue.h>

#include "entity_manager.h"

// pb la reference de l'entity existe toujours
// on peut supprimer deux fois la même entity
// ou indexer un truc suppr

ents_entity_manager_t ents_entity_manager_new()
{
    ents_entity_manager_t em = {
        .available_ids = dats_queue_new(sizeof(uint64_t)),
        .next_higher_available_id = 0
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

    ents_entity_t e = {
        .id = self->next_higher_available_id
    };
    self->next_higher_available_id++;
    return e;
}

void ents_entity_manager_destroy_entity(ents_entity_manager_t *self, ents_entity_t entity)
{
    dats_queue_enqueue(&self->available_ids, &entity.id);
}

void ents_entity_manager_free(ents_entity_manager_t *self)
{
    dats_queue_free(&self->available_ids);
    self->next_higher_available_id = 0;
}
