#include <stdio.h>
#include <stdlib.h>

#include "../src/ents.h"

int main()
{
    EntityManager em = EntityManager_Value();
    //Entity entity = EntityManager_CreateEntity();

    EntityManager_Drop(&em);
    return EXIT_SUCCESS;
}


// Usage
// World world = World_Ereate();
// Entity entity = World_Entity();
