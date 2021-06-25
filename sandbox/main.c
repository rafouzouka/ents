#include <stdio.h>
#include <stdlib.h>

#include "../src/ents.h"

int main()
{
    // EntityManager em = EntityManager_Value();
    // //Entity entity = EntityManager_CreateEntity();
    // EntityManager_Drop(&em);

    LinkedList ll = LinkedList_value(sizeof(char));
    char c = 'c';
    LinkedList_insert_head(&ll, &c);

    LinkedList_drop(&ll);

    return EXIT_SUCCESS;
}


// Usage
// World world = World_Ereate();
// Entity entity = World_Entity();
