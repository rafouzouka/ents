#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/ents.h"

typedef struct
{
    int64_t x;
    int64_t y;
} Position;

void printoche(const void* data)
{
    const char *c = data;
    printf("data: %c\n", *c);
}

int main()
{
    Position pos1 = { 255, 552 };
    Position pos2 = { 9999, 8888 };
    Position pos3 = { 11, 12 };

    DenseVec dv = DenseVec_Value(sizeof(Position));

    DenseVec_Print(&dv);
    
    DenseVec_Insert(&dv, 1, &pos1);
    DenseVec_Print(&dv);

    DenseVec_Insert(&dv, 0, &pos2);
    DenseVec_Print(&dv);

    DenseVec_Insert(&dv, 2, &pos3);
    DenseVec_Print(&dv);

    DenseVec_Remove(&dv, 0);
    // DenseVec_Print(&dv);

    DenseVec_Drop(&dv);
    return EXIT_SUCCESS;
}

// i was on dense vec .c the insert metod

// Usage
// World world = World_Ereate();
// Entity entity = World_Entity();
