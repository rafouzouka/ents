#include "component_manager.h"
#include <dats/dynamic_array.h>

ents_component_manager_t ents_component_manager_new()
{
    ents_component_manager_t cm = {
        .component_descs = dats_dynamic_array_new(4, sizeof(ents_component_desc_t)),
    };

    return cm;
}

void ents_component_manager_free(ents_component_manager_t *self)
{
    dats_dynamic_array_free(&self->component_descs);    
}
