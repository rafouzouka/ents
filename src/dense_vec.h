#ifndef DENSE_VEC_H
#define DENSE_VEC_H

// Redirection [] [] [] []
// Data        [] [] [] []

#include <stdint.h>

#include "dynamic_array.h"

typedef struct {
    DynamicArray lookup;
    DynamicArray data;
} DenseVec;

DenseVec DenseVec_Value(uint64_t dataByteSize);

void DenseVec_Insert(DenseVec *self, uint64_t index, const void *data);

#endif