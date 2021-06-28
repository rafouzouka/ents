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

static void _print_lookup(const void* data)
{
    const LookupCell *lc = data;

    if (lc->state == LookupState_EMPTY)
    {
        printf("[N] ");
    }
    else if (lc-> state == LookupState_DATA)
    {
        printf("[%lu] ", lc->index);
    }
}

void DenseVec_Print(const DenseVec *self)
{
    printf("Lookup Table:\n");
    DynamicArray_map(&self->lookup, _print_lookup);
    printf("\n");
}

void DenseVec_Insert(DenseVec *self, uint64_t index, const void *data)
{
    LookupCell newCell = {
        LookupState_DATA,
        self->dataArrayLength
    };
    DynamicArray_insert(&self->lookup, index, &newCell);
    DynamicArray_insert(&self->data, self->dataArrayLength, data);
    self->dataArrayLength++;
}

// ici certainement une erreur s'il n'y avait rien de base
// a verifier
void DenseVec_Remove(DenseVec *self, uint64_t index)
{
    LookupCell clearedCell = {
        LookupState_EMPTY,
        0
    };
    const LookupCell *currentCell = DynamicArray_get(&self->lookup, index);
    // uint64_t dataIndexToRemove = currentCell->index;
    DynamicArray_insert(&self->lookup, index, &clearedCell);

    uint64_t lookupCellIndexDataToFind = self->dataArrayLength - 1;

    printf("lookupitem: %lu\n", lookupCellIndexDataToFind);

    // LookupCell cellToFind = {
    //     LookupState_DATA,
    //     lookupCellIndexDataToFind
    // };
    // uint64_t res = DynamicArray_find(&self->lookup, &cellToFind);

    // printf("res: %lu\n", res);

    // const void *data = DynamicArray_get(&self->data, self->dataArrayLength-1);
    
    // DynamicArray_insert(&self->lookup, da, const void *data)
}
