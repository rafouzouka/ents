#ifndef DENSE_VEC_H
#define DENSE_VEC_H

// Redirection [] [] [] []
// Data        [] [] [] []

#include <stdint.h>

#include "dynamic_array.h"

typedef enum
{
    EMPTY,
    DATA
} LookupState;

typedef struct
{
    LookupState state;
    uint64_t index;
} LookupCell;

typedef struct {
    DynamicArray lookup;
    DynamicArray data;
    uint64_t dataArrayLength;
} DenseVec;

DenseVec DenseVec_Value(uint64_t dataByteSize);

// !! attention a la valeur de LookupCell il est
// possible que ce ne soit pas empty par défaut

// !! On ne doit pas pouvoir insérer deux fois au même endroit
void DenseVec_Insert(DenseVec *self, uint64_t index, const void *data);

void DenseVec_Remove(DenseVec *self, uint64_t index);

void DenseVec_Drop(DenseVec *self);

#endif