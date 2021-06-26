#include "string.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>

#include "linked_list.h"

static void _set_data(Node *node, void *src, uint64_t size);

LinkedList LinkedList_value(uint64_t dataSize)
{
    LinkedList ll = { dataSize, NULL, NULL, 0 };
    return ll;
}

void LinkedList_drop(LinkedList *self)
{
    Node *currentNode = self->head;
    Node *nextNode;
    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        free(currentNode->data);
        free(currentNode);
        currentNode = nextNode;
    }
    self = NULL;
}

void LinkedList_print(const LinkedList *self)
{
    printf("LinkedList size: %lu\n", self->length);

    Node *currentNode = self->head;
    while (currentNode != NULL)
    {
        switch (self->dataSize)
        {
            case sizeof(char):
            {
                char *data = currentNode->data;
                printf("[%c] -> ", *data);
                break;
            }
            case sizeof(int):
            {
                int *data = currentNode->data;
                printf("[%d] -> ", *data);
                break;
            }
            case sizeof(double):
            {
                double *data = currentNode->data;
                printf("[%f] -> ", *data);
                break;
            }
        }
        currentNode = currentNode->next;
    }
    printf("NULL\n\n");
}

int64_t LinkedList_find(const LinkedList *self, void *data)
{
    int64_t index = 0;
    Node *currentNode = self->head;
    while (currentNode != NULL)
    {
        if (memcmp(currentNode->data, data, self->dataSize) == 0)
        {
            return index;
        }
        currentNode = currentNode->next;
        index++;
    }
    return -1;
}

int64_t LinkedList_length(const LinkedList *self)
{
    return self->length;
}

void LinkedList_insert_index(LinkedList *self, void *data, int64_t index)
{
    if (index <= 0)
    {
        LinkedList_insert_head(self, data);
    }
    else if (index >= self->length-1)
    {
        LinkedList_insert_tail(self, data);
    }
    else
    {
        Node *new_node = malloc(sizeof(Node));
        _set_data(new_node, data, self->dataSize);
        
        Node *currentNode = self->head;
        for (int64_t i = 0; i < index-1; i++)
        {
            currentNode = currentNode->next;
        }
        new_node->next = currentNode->next;
        currentNode->next = new_node;
        self->length++;
    }
}

void LinkedList_insert_head(LinkedList *self, void *data)
{
    Node *new_node = malloc(sizeof(Node));
    
    _set_data(new_node, data, self->dataSize);

    if (self->length == 0)
    {
        new_node->next = NULL;
        self->tail = new_node;
    }
    else
    {
        new_node->next = self->head;
    }
    self->head = new_node;
    self->length++;
}

void LinkedList_insert_tail(LinkedList *self, void *data)
{
    Node *new_node = malloc(sizeof(Node));

    new_node->next = NULL;
    _set_data(new_node, data, self->dataSize);

    if (self->length <= 0)
    {
        self->head = new_node;
    }
    else
    {
        self->tail->next = new_node; 
    }
    self->tail = new_node;
    self->length++;
}

void LinkedList_remove_index(LinkedList *self, int64_t index)
{
    if (index == 0)
    {
        Node *nextNode = self->head->next;
        free(self->head->data);
        free(self->head);
        self->head = nextNode;
        return;
    }

    Node *currentNode = self->head;

    for (int64_t i = 0; i <= index-2; i++)
    {
        currentNode = currentNode->next;
    }

    Node *nodeToFree = currentNode->next;
    Node *nextNode = nodeToFree->next;

    free(nodeToFree->data);
    free(nodeToFree);

    currentNode->next = nextNode;
    self->length--;
}

// You must free the void* after using the data
void *LinkedList_remove_head(LinkedList *self)
{
    Node *temp = self->head->next;
    void *data = self->head->data; 
    // free(self->head->data);
    free(self->head);
    self->head = temp;
    self->length--;
    return data;
}

static void _set_data(Node *node, void *src, uint64_t size)
{
    node->data = malloc(size);
    memcpy(node->data, src, size);
}