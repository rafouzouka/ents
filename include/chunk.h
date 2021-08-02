#ifndef CHUNK_H
#define CHUNK_H

#include <stdint.h>

#include <dats/dats.h>

typedef struct
{
    dats_dynamic_array_t components;
} ents_chunk_t;

#endif