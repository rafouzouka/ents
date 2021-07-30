#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdint.h>

#include <dats/dats.h>

typedef struct
{
    const char *name;
    const char *query;
    dats_bitset_t bitset;
    void (*callback)(const char *str);
} ents_system_t;

#endif