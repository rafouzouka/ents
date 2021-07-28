#include <dats/bitset.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include <dats/queue.h>

#include "entity_manager.h"

ents_entity_manager_t ents_entity_manager_new()
{
    ents_entity_manager_t em = {
        .available_ids = dats_queue_new(sizeof(uint64_t)),
        .bitsets = dats_dynamic_array_new(4, sizeof(dats_bitset_t)),
        .bitset_size = 0,
        .next_higher_available_id = 0,
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

        dats_bitset_t bitset = dats_bitset_new(self->bitset_size);
        dats_dynamic_array_insert(&self->bitsets, e.id, &bitset);
        return e;
    }
    else
    {
        ents_entity_t e = {
            .id = self->next_higher_available_id
        };
        self->next_higher_available_id++;

        dats_bitset_t bitset = dats_bitset_new(self->bitset_size);
        dats_dynamic_array_add(&self->bitsets, &bitset);

        return e;
    }

}

void ents_entity_manager_destroy_entity(ents_entity_manager_t *self, ents_entity_t entity)
{
    dats_queue_enqueue(&self->available_ids, &entity.id);
}

void ents_entity_manager_set_bitset_size(ents_entity_manager_t *self, uint64_t bitset_size)
{
    self->bitset_size = bitset_size;
}

void ents_entity_manager_set(ents_entity_manager_t *self, ents_entity_t entity, uint64_t component_type)
{
    dats_bitset_t bitset = dats_bitset_new(self->bitset_size);

    if (entity.id > dats_dynamic_array_length(&self->bitsets) - 1)
    {
        dats_dynamic_array_add(&self->bitsets, &bitset);
    }
    else
    {
        dats_dynamic_array_insert(&self->bitsets, entity.id, &bitset);
    }
}

void ents_entity_manager_print(const ents_entity_manager_t *self)
{
    uint64_t len = dats_dynamic_array_length(&self->bitsets);
    printf("LENGTH: %ld\n", len);

    for (uint64_t i = 0; i < dats_dynamic_array_length(&self->bitsets); i++)
    {
        printf("[%ld] -> ", i);
        const dats_bitset_t *bitset = dats_dynamic_array_get(&self->bitsets, i);
        dats_bitset_print(bitset);
    }
    printf("\n");
}

void ents_entity_manager_free(ents_entity_manager_t *self)
{
    for (uint64_t i = 0; i < dats_dynamic_array_length(&self->bitsets); i++)
    {
        dats_bitset_free(dats_dynamic_array_ref(&self->bitsets, i));
    }

    dats_dynamic_array_free(&self->bitsets);
    dats_queue_free(&self->available_ids);
    self->next_higher_available_id = 0;
}
