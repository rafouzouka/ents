#ifndef RECORD_H
#define RECORD_H

#include <stdint.h>

#include "archetype.h"

typedef struct
{
    ents_archetype_t *archetype;
    uint64_t row;
} ents_record_t;

#endif