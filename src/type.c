#include "type.h"

ents_type_t ents_type_new()
{
    ents_type_t type = {
        .component_ids = dats_dynamic_array_new(4, sizeof(uint64_t))
    };

    return type;
}

void ents_type_free(ents_type_t *self)
{
    dats_dynamic_array_free(&self->component_ids);
}
