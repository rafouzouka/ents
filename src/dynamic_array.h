#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdint.h>

typedef struct
{
    int64_t item_size;
    int64_t length;
    int64_t capacity;
    void *buffer;
} DynamicArray;

DynamicArray DynamicArray_value(int64_t capacity, int64_t item_size);

void DynamicArray_drop(DynamicArray *self);

void DynamicArray_print(const DynamicArray *self);

void DynamicArray_data(const DynamicArray *self);

void DynamicArray_insert(DynamicArray *self, int64_t index, const void *data);

const void *DynamicArray_get(DynamicArray *self, int64_t index);

void DynamicArray_clear(DynamicArray *self);

int64_t DynamicArray_length(DynamicArray *self);

#endif