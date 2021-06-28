#include <stdint.h>
#include <stdio.h>

#include "dense_vec.h"

DenseVec DenseVec_Value(uint64_t dataByteSize)
{
    DenseVec dv = {
        DynamicArray_value(4, sizeof(LookupCell)),
        DynamicArray_value(4, dataByteSize),
        0
    };

    return dv;
}

void DenseVec_Drop(DenseVec *self)
{
    DynamicArray_drop(&self->lookup);
    DynamicArray_drop(&self->data);
}

// void DenseVec_Insert(DenseVec *self, uint64_t index, const void *data)
// {
//     DynamicArray_insert(&self->lookup, index, &self->dataArrayLength);
//     self->dataArrayLength++;
// }
