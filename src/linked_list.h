#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdint.h>

typedef struct
{
    void *data;
    void *next;
} Node;

typedef struct
{
    const uint64_t dataSize;
    Node *head;
    Node *tail;
    int64_t length;
} LinkedList;

// create 
LinkedList LinkedList_value(uint64_t dataSize);

// delete
void LinkedList_drop(LinkedList *self);

// print
void LinkedList_print(const LinkedList *self);

// search
int64_t LinkedList_find(const LinkedList *self, const void *data);

// get length
int64_t LinkedList_length(const LinkedList *self);

// insert index
void LinkedList_insert_index(LinkedList *self, const void *data, int64_t index);

// insert head
void LinkedList_insert_head(LinkedList *self, const void *data);

// insert tail
void LinkedList_insert_tail(LinkedList *self, const void *data);

// remove index
void LinkedList_remove_index(LinkedList *self, int64_t index);

// remove head
void *LinkedList_remove_head(LinkedList *self);

#endif