#include <stdio.h>
#include <stdlib.h>

#include "../src/ents.h"

int main()
{
    EntityManager em = EntityManager_Value();
    Entity entity = EntityManager_CreateEntity(&em);
    Entity entity2 = EntityManager_CreateEntity(&em);
    Entity entity3 = EntityManager_CreateEntity(&em);

    printf("Entity ID: %ld\n", entity.id);
    printf("Entity ID: %ld\n", entity2.id);
    printf("Entity ID: %ld\n", entity3.id);

    // EntityManager_DestroyEntity(&em, entity2);
    EntityManager_DestroyEntity(&em, entity3);

    Entity entity4 = EntityManager_CreateEntity(&em);
    Entity entity5 = EntityManager_CreateEntity(&em);

    printf("Entity ID: %ld\n", entity4.id);
    printf("Entity ID: %ld\n", entity5.id);

    EntityManager_Drop(&em);
    return EXIT_SUCCESS;
}


// Usage
// World world = World_Ereate();
// Entity entity = World_Entity();
