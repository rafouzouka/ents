#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#include "linked_list.h"

typedef struct Queue
{
    LinkedList ll;
} Queue;

Queue Queue_value(uint64_t size);

void Queue_drop(Queue *self);

void Queue_print(const Queue *self);

void Queue_enqueue(Queue *self, void *data);

void Queue_dequeue(Queue *self);

bool Queue_contains(const Queue *self, void *data);

bool IsEmpty(const Queue *self);

#endif