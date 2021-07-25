#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <dats/dynamic_array.h>

#include "component_manager.h"


ents_component_manager_t ents_component_manager_new()
{
    ents_component_manager_t cm = {
        .component_array = dats_dynamic_array_new(4, sizeof(dats_dynamic_array_t)),
        .number_of_component_variation = 0
    };

    return cm;
}

void ents_component_manager_register(ents_component_manager_t *self, uint64_t data_size)
{
    dats_dynamic_array_t da = dats_dynamic_array_new(4, data_size);

    dats_dynamic_array_add(&self->component_array, &da);
    self->number_of_component_variation++;
}

void ents_component_manager_print(const ents_component_manager_t *self)
{
    for (uint64_t i = 0; i < self->number_of_component_variation; i++)
    {
        const dats_dynamic_array_t *da = dats_dynamic_array_get(&self->component_array, i);
        
        printf("DynamicArray %ld :\n", i);
        uint64_t length = dats_dynamic_array_length(da);
        if (length == 0)
        {
            printf("EMPTY");
        } 
        else 
        {
            for (uint64_t j = 0; j < length; j++)
            {
                printf("[ITEM] ");
            }
        }
        printf("\n\n");
    }
}

void ents_component_manager_free(ents_component_manager_t *self)
{
    for (uint64_t i = 0; i < self->number_of_component_variation; i++)
    {
        dats_dynamic_array_t *da = dats_dynamic_array_ref(&self->component_array, i);
        dats_dynamic_array_free(da);
    }

    dats_dynamic_array_free(&self->component_array);
}
