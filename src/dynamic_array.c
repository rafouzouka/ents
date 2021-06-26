#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"

static void _OOM_GUARD(void *ptr, char *file_name, int line_number);
static void _ensure_capacity(DynamicArray *self, int64_t wanted_capacity);

DynamicArray DynamicArray_value(int64_t capacity, int64_t item_size)
{
    DynamicArray da = {
        item_size,
        0,
        capacity,
        calloc(capacity, sizeof(item_size)),
    };
    _OOM_GUARD(da.buffer, __FILE__, __LINE__);
    return da;
}

void DynamicArray_drop(DynamicArray *self)
{
    free(self->buffer);
    self->buffer = NULL;
    self->capacity = 0;
    self->length = 0;
}

void DynamicArray_print(const DynamicArray *self)
{
    printf("Item Size: %ld, Capacity: %ld, Length: %ld\n", self->item_size, self->capacity, self->length);
}

void DynamicArray_data(const DynamicArray *self)
{
    char *buffer = self->buffer;
    int64_t capacity = self->capacity; 

    for (int64_t i = 0; i < capacity; i++)
    {
        printf("[%c], ", buffer[i]);
    }
    printf("\n");
}

void DynamicArray_insert(DynamicArray *self, int64_t index, const void *data)
{
    _ensure_capacity(self, index+1);
    if (index > self->length)
    {
        self->length = index;
    }
    int8_t *buffer = self->buffer;
    memcpy(&buffer[index], data, self->item_size);
}

const void *DynamicArray_get(DynamicArray *self, int64_t index)
{
    int8_t *buffer = self->buffer;
    return &buffer[index * self->item_size];
}

void DynamicArray_clear(DynamicArray *self)
{
    int8_t *buffer = self->buffer;
    memset(buffer, 0, self->capacity * self->item_size);
    self->length = 0;
}

int64_t DynamicArray_length(DynamicArray *self)
{
    return self->length;
}

static void _OOM_GUARD(void *ptr, char *file_name, int line_number)
{
    if (ptr == NULL)
    {
        fprintf(stderr, "Allocating memory failed. FILE: %s, LINE: %d.\n", file_name, line_number);
        exit(EXIT_FAILURE);
    }
}

static void _ensure_capacity(DynamicArray *self, int64_t wanted_capacity)
{
    if (self->capacity < wanted_capacity)
    {
        self->capacity = wanted_capacity;
        self->buffer = realloc(self->buffer, self->capacity * self->item_size);
        _OOM_GUARD(self->buffer, __FILE__, __LINE__);
    }
}
