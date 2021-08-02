#include "type.h"
#include <dats/dynamic_array.h>
#include <stdint.h>
#include <stdio.h>

ents_type_t ents_type_new()
{
    ents_type_t type = {
        .component_ids = dats_dynamic_array_new(4, sizeof(uint64_t))
    };

    return type;
}

void ents_type_add(ents_type_t *self, uint64_t component_type)
{
    dats_dynamic_array_add(&self->component_ids, &component_type);
}

void ents_type_remove(ents_type_t *self, uint64_t component_type)
{
    dats_dynamic_array_remove(&self->component_ids, &component_type);
}

bool ents_type_has(const ents_type_t *self, uint64_t component_type)
{
    for (uint64_t i = 0; i < dats_dynamic_array_length(&self->component_ids); i++)
    {
        const uint64_t *c_type = dats_dynamic_array_get(&self->component_ids, i);
        if (component_type == *c_type)
        {
            return true;
        }
    }
    return false;
}

void ents_type_clear(ents_type_t *self)
{
    dats_dynamic_array_clear(&self->component_ids);
}

ents_type_t ents_type_clone(const ents_type_t *self)
{
    ents_type_t clone = {
        .component_ids = dats_dynamic_array_clone(&self->component_ids),
    };

    return clone;
}

void ents_type_print(const ents_type_t *self)
{
    for (uint64_t i = 0; i < dats_dynamic_array_length(&self->component_ids); i++)
    {
        const uint64_t *c_type = dats_dynamic_array_get(&self->component_ids, i);
        printf("%ld, ", *c_type);
    }
}

void ents_type_free(ents_type_t *self)
{
    dats_dynamic_array_free(&self->component_ids);
}
