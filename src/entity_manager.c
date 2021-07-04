#include <dats/dats.h>
#include <dats/queue.h>

#include "entity_manager.h"

void ents_create_queue()
{
    dats_queue_t t = dats_queue_new(sizeof(char));

    dats_queue_free(&t);
}


// EntityManager EntityManager_Value()
// {
//     EntityManager em = {
//         Queue_value(sizeof(uint64_t)),
//         0,
//         0
//     };
//     return em;
// }

// void EntityManager_Drop(EntityManager *self)
// {
//     Queue_drop(&self->ids);
//     self = NULL;
// }

// Entity EntityManager_CreateEntity(EntityManager *self)
// {
//     if (self->queueSize <= 0)
//     {
//         Entity newEntity = { self->nextId };
//         self->nextId++;
//         return newEntity;
//     }

//     uint64_t *data_ptr = Queue_dequeue(&self->ids);
//     Entity e = { *data_ptr };
//     free(data_ptr);
//     self->queueSize--;

//     return e;
// }

// void EntityManager_DestroyEntity(EntityManager *self, Entity entity)
// {
//     Queue_enqueue(&self->ids, &entity.id);
//     self->queueSize++;
// }
