#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/ents.h"
#include "../../dats/src/dats.h"

int main()
{
    printf("Salut les gens :D\n");

    dats_queue_t queue = dats_queue_new(sizeof(int));
    return EXIT_SUCCESS;
}

// Usage
// World world = World_Ereate();
// Entity entity = World_Entity();
