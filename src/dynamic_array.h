#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdint.h>

typedef struct
{
    uint64_t item_size;
    uint64_t length;
    uint64_t capacity;
    void *buffer;
} DynamicArray;

DynamicArray DynamicArray_value(uint64_t capacity, uint64_t item_size);

void DynamicArray_drop(DynamicArray *self);

void DynamicArray_print(const DynamicArray *self);

void DynamicArray_map(const DynamicArray *self, void (*map)(const void *data));

uint64_t DynamicArray_find(DynamicArray *self, const void *dataToFind);

void DynamicArray_insert(DynamicArray *self, uint64_t index, const void *data);

const void *DynamicArray_get(DynamicArray *self, uint64_t index);

void DynamicArray_clear(DynamicArray *self);

uint64_t DynamicArray_length(DynamicArray *self);

#endif