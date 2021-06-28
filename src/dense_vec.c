#include <stdint.h>
#include <stdio.h>

#include "dense_vec.h"
#include "dynamic_array.h"

DenseVec DenseVec_Value(uint64_t dataByteSize)
{
    DenseVec dv = {
        DynamicArray_value(4, sizeof(LookupCell)),
        DynamicArray_value(4, dataByteSize),
        0
    };

    // No need to initialize data here because Dynamic
    // Array automaticly set the memory to 0
    // LookupState will be set to Empty by default.

    return dv;
}

void DenseVec_Drop(DenseVec *self)
{
    DynamicArray_drop(&self->lookup);
    DynamicArray_drop(&self->data);
}

// void DenseVec_Print(const DenseVec *self)
// {
//     // to change this
//     // printf("Lookup Table:\n");

//     // printf("Data   Table:\n");

//     // printf("Data length: %ld\n", self->dataArrayLength);
// }

// void DenseVec_Insert(DenseVec *self, uint64_t index, const void *data)
// {
//     DynamicArray_insert(&self->lookup, index, &self->dataArrayLength);
//     self->dataArrayLength++;
// }
