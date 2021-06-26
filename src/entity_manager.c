#include <stdint.h>
#include <stdlib.h>

#include "queue.h"
#include "entity_manager.h"

EntityManager EntityManager_Value()
{
    EntityManager em = {
        Queue_value(sizeof(uint64_t)),
        0,
        0
    };
    return em;
}

void EntityManager_Drop(EntityManager *self)
{
    Queue_drop(&self->ids);
    self = NULL;
}

// Entity EntityManager_CreateEntity(EntityManager *self)
// {
//     if (self->queueSize <= 0)
//     {
//         Entity newEntity = { self->nextId };
//         self->nextId++;
//         return newEntity;
//     }

//     //Queue_dequeue(Queue *self)
// }
