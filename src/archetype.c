#include <dats/dynamic_array.h>
#include <stdint.h>

#include "archetype.h"
#include "type.h"

// ents_archetype_t ents_archetype_new(const ents_type_t *type)
// {
//     ents_archetype_t archetype = {
//         .type = ents_type_clone(type),
//         .entity_ids = dats_dynamic_array_new(4, sizeof(uint64_t)),
//         .chunck_components = dats_dynamic_array_new(4, sizeof(ents_components_t)),
//     };

//     return archetype;
// }

// void ents_archetype_free(ents_archetype_t *self)
// {
//     ents_type_free(&self->type);
//     dats_dynamic_array_free(&self->entity_ids);
//     dats_dynamic_array_free(&self->chunck_components);
// }
