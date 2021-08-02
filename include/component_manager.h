#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <dats/dats.h>

#include "component.h"

typedef struct
{
    dats_dynamic_array_t component_descs;
} ents_component_manager_t;

ents_component_manager_t ents_component_manager_new();

void ents_component_manager_free(ents_component_manager_t *self);

#endif