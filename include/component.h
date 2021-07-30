#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdint.h>

typedef struct
{
    const char *name;
    uint64_t data_size;
} ents_component_desc_t;

#endif