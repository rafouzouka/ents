#include "string.h"
#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

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

// void LinkedList_print(const LinkedList *self)
// {
//     printf("LinkedList size: %lu\n", self->length);

//     Node *currentNode = self->head;
//     while (currentNode != NULL)
//     {
//         printf("[%d] -> ", currentNode->data);
//         currentNode = currentNode->next;
//     }
//     printf("NULL\n\n");
// }

// int64_t LinkedList_find(const LinkedList *self, char data)
// {
//     int64_t index = 0;
//     Node *currentNode = self->head;
//     while (currentNode != NULL)
//     {
//         if (data == currentNode->data)
//         {
//             return index;
//         }
//         currentNode = currentNode->next;
//         index++;
//     }
//     return -1;
// }

// int64_t LinkedList_length(const LinkedList *self)
// {
//     return self->length;
// }

// void LinkedList_insert_index(LinkedList *self, char data, int64_t index)
// {
//     if (index <= 0)
//     {
//         LinkedList_insert_head(self, data);
//     }
//     else if (index >= self->length-1)
//     {
//         LinkedList_insert_tail(self, data);
//     }
//     else
//     {
//         Node *new_node = malloc(sizeof(Node));
//         new_node->data = data;
        
//         Node *currentNode = self->head;
//         for (int64_t i = 0; i < index-1; i++)
//         {
//             currentNode = currentNode->next;
//         }
//         new_node->next = currentNode->next;
//         currentNode->next = new_node;
//         self->length++;
//     }
// }

void LinkedList_insert_head(LinkedList *self, void *data)
{
    Node *new_node = malloc(sizeof(Node));
    
    new_node->data = malloc(sizeof(self->dataSize));
    memcpy(new_node->data, data, self->dataSize);

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

// void LinkedList_insert_tail(LinkedList *self, char data)
// {
//     Node *new_node = malloc(sizeof(Node));
//     new_node->data = data;
//     new_node->next = NULL;

//     if (self->length <= 0)
//     {
//         self->head = new_node;
//     }
//     else
//     {
//         self->tail->next = new_node; 
//     }
//     self->tail = new_node;
//     self->length++;
// }

// void LinkedList_remove_index(LinkedList *self, int64_t index)
// {
//     Node *currentNode = self->head;
//     for (int64_t i = 0; i < index-1; i++)
//     {
//         currentNode = currentNode->next;
//     }
//     Node *temp = currentNode->next;
//     temp = temp->next;
//     free(currentNode->next);
//     currentNode->next = temp;
//     self->length--;
// }

// void LinkedList_remove_head(LinkedList *self)
// {
//     Node *temp = self->head->next;
//     free(self->head);
//     self->head = temp;
//     self->length--;
// }
