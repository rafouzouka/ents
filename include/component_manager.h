#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <dats/dats.h>

#include "component.h"

typedef struct
{
    dats_dynamic_array_t component_descs;
    uint64_t number_of_component_variation;
} ents_component_manager_t;

ents_component_manager_t ents_component_manager_new();

ents_component_type_t ents_component_manager_component_register(ents_component_manager_t *self, ents_component_desc_t *desc);

void ents_component_manager_free(ents_component_manager_t *self);

#endif