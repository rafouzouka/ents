#include "queue.h"

Queue Queue_value()
{
    Queue q = { LinkedList_value(sizeof(char)) };
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

void Queue_enqueue(Queue *self, char c)
{
    LinkedList_insert_tail(&self->ll, c);
}

void Queue_dequeue(Queue *self)
{
    LinkedList_remove_head(&self->ll);
}

bool Queue_contains(const Queue *self, char c)
{
    if (LinkedList_find(&self->ll, c) != -1)
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
