#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <stdint.h>

#include "entity.h"
#include "queue.h"

typedef struct {
    Queue ids;
    uint64_t queueSize;
    uint64_t nextId;
} EntityManager;

EntityManager EntityManager_Value();

void EntityManager_Drop(EntityManager *self);

Entity EntityManager_CreateEntity(EntityManager *self);

void EntityManager_DestroyEntity(EntityManager *self, Entity entity);

#endif