#include "queue.h"
#include <stdint.h>

Queue Queue_value(uint64_t size)
{
    Queue q = { LinkedList_value(size) };
    return q;
}

void Queue_drop(Queue *self)
{
    LinkedList_drop(&self->ll);
}

void Queue_print(const Queue *self)
{
    LinkedList_print(&self->ll);
}

void Queue_enqueue(Queue *self, void *data)
{
    LinkedList_insert_tail(&self->ll, data);
}

void Queue_dequeue(Queue *self)
{
    LinkedList_remove_head(&self->ll);
}

bool Queue_contains(const Queue *self, void *data)
{
    if (LinkedList_find(&self->ll, data) != -1)
    {
        return true;
    }
    return false;
}

bool IsEmpty(const Queue *self)
{
    if (LinkedList_length(&self->ll) <= 0)
    {
        return true;
    }
    return false;
}
