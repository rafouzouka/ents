#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <stdint.h>
#include <dats/dats.h>

typedef struct
{
    dats_dynamic_array_t component_array;    
    uint64_t number_of_component_variation;
} ents_component_manager_t;

ents_component_manager_t ents_component_manager_new();

void ents_component_manager_register(ents_component_manager_t *self, uint64_t data_size);

void ents_component_manager_print(const ents_component_manager_t *self);

void ents_component_manager_free(ents_component_manager_t *self);

#endif