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
    int d = 998;
    int e = 333;
    int f = 212121;
    int z = 846684668;

    LinkedList_print(&ll);

    printf("size: %ld\n", LinkedList_length(&ll));
    LinkedList_insert_head(&ll, &c);
    printf("size: %ld\n", LinkedList_length(&ll));

    LinkedList_insert_tail(&ll, &d);
    printf("size: %ld\n", LinkedList_length(&ll));
    LinkedList_print(&ll);

    LinkedList_insert_tail(&ll, &e);
    printf("size: %ld\n", LinkedList_length(&ll));
    LinkedList_print(&ll);

    LinkedList_remove_index(&ll, 0);
    printf("size: %ld\n", LinkedList_length(&ll));
    LinkedList_print(&ll);

    LinkedList_insert_index(&ll, &f, 1);
    printf("size: %ld\n", LinkedList_length(&ll));
    LinkedList_print(&ll);

    LinkedList_insert_index(&ll, &d, 2);
    printf("size: %ld\n", LinkedList_length(&ll));
    LinkedList_print(&ll);

    LinkedList_insert_index(&ll, &z, 25);
    printf("size: %ld\n", LinkedList_length(&ll));
    LinkedList_print(&ll);

    printf("Index is: %ld\n", LinkedList_find(&ll, &f));

    LinkedList_drop(&ll);
    return EXIT_SUCCESS;
}


// Usage
// World world = World_Ereate();
// Entity entity = World_Entity();
