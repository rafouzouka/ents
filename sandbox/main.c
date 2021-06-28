#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/ents.h"

typedef struct
{
    int64_t x;
    int64_t y;
} Position;

void print(const void *data)
{
    const Position *content = data;
    printf("[ X: %ld ", content->x);
    printf("Y: %ld ]\n\n", content->y);

    // const Position *da = data;
    // printf("data: %ld\n", da->x);
    // printf("data: %ld\n", da->y);
}

int main()
{
    // DenseVec dv = DenseVec_Value(sizeof(char));
    // // Position p = { 5, 6 };

    // DenseVec_Print(&dv);
    // DenseVec_Insert(&dv, 0, &a);
    // DenseVec_Print(&dv);

    // // DenseVec_Insert(&dv, 0, &p);

    Position pos1 = { 851, 999 };
    Position pos2 = { 125, 334 };
    Position pos3 = { 16, 32 };

    DynamicArray da = DynamicArray_value(4, sizeof(Position));

    DynamicArray_insert(&da, 1, &pos1);
    DynamicArray_insert(&da, 5, &pos2);
    DynamicArray_insert(&da, 8, &pos3);

    DynamicArray_map(&da, print);

    DynamicArray_drop(&da);

    return EXIT_SUCCESS;
}

// i was on dense vec .c the insert metod

// Usage
// World world = World_Ereate();
// Entity entity = World_Entity();
