#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/ents.h"

typedef struct
{
    int64_t x;
    int64_t y;
} Position;

int main()
{
    DenseVec dv = DenseVec_Value(sizeof(Position));
    //DenseVec dv = 

    return EXIT_SUCCESS;
}

// i was on dense vec .c the insert metod


// Usage
// World world = World_Ereate();
// Entity entity = World_Entity();
