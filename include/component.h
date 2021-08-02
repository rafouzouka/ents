#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdint.h>

typedef struct
{
    uint64_t id;
} ents_component_type_t;

typedef struct
{
    const char *name;
    uint64_t data_size;
    ents_component_type_t type;
} ents_component_desc_t;

#endif