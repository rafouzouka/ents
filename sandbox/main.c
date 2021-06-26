#include <stdio.h>
#include <stdlib.h>

#include "../src/ents.h"

int main()
{
    // EntityManager em = EntityManager_Value();
    // //Entity entity = EntityManager_CreateEntity();
    // EntityManager_Drop(&em);

    LinkedList ll = LinkedList_value(sizeof(int));
    int c = 55555;

    LinkedList_print(&ll);

    printf("size: %ld\n", LinkedList_length(&ll));
    LinkedList_insert_head(&ll, &c);
    printf("size: %ld\n", LinkedList_length(&ll));

    LinkedList_insert_tail(&ll, &c);
    printf("size: %ld\n", LinkedList_length(&ll));

    LinkedList_print(&ll);

    LinkedList_drop(&ll);
    return EXIT_SUCCESS;
}


// Usage
// World world = World_Ereate();
// Entity entity = World_Entity();
