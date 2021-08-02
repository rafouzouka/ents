#include "component_manager.h"
#include <dats/dynamic_array.h>

ents_component_manager_t ents_component_manager_new()
{
    ents_component_manager_t cm = {
        .component_descs = dats_dynamic_array_new(4, sizeof(ents_component_desc_t)),
        .number_of_component_variation = 0,
    };

    return cm;
}

ents_component_type_t ents_component_manager_component_register(ents_component_manager_t *self, ents_component_desc_t *desc)
{
    ents_component_type_t component_type = {
        .id = self->number_of_component_variation,
    };
    desc->type = component_type;
    dats_dynamic_array_add(&self->component_descs, desc);
    self->number_of_component_variation++;
    return component_type;
}

void ents_component_manager_free(ents_component_manager_t *self)
{
    dats_dynamic_array_free(&self->component_descs);    
}
