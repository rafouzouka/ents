#ifndef MACRO_H
#define MACRO_H

#define ENTS_ID_COMPONENT(component_type) id_ ## component_type 

#define ENTS_WORLD_REGISTER(world, component_type) \
    uint64_t ENTS_ID_COMPONENT(component_type) = ents_world_register(&world, sizeof(component_type))

#define ENTS_WORLD_SET(world, entity, component_type, ...) \
    ents_world_set(&world, entity, ENTS_ID_COMPONENT(component_type), &(component_type)__VA_ARGS__)

#define ENTS_WORLD_GET(world, entity, component_type) \
    ents_world_get(&world, entity, ENTS_ID_COMPONENT(component_type))

#define ENTS_WORLD_REF(world, entity, component_type) \
    ents_world_ref(&world, entity, ENTS_ID_COMPONENT(component_type))

#endif