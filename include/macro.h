#ifndef MACRO_H
#define MACRO_H

#define ENTS_COMPONENT_ID(component_type) id_ ## component_type 

#define ENTS_WORLD_COMPONENT_REGISTER(world, component_type) \
    uint64_t ENTS_COMPONENT_ID(component_type) = ents_world_component_register(&world, &(ents_component_desc_t){ \
        .data_size = sizeof(component_type), \
        .name = #component_type \
    }) \

#define ENTS_WORLD_COMPONENT_SET(world, entity, component_type, ...) \
    ents_world_component_set(&world, entity, ENTS_COMPONENT_ID(component_type), &(component_type)__VA_ARGS__)

#define ENTS_WORLD_COMPONENT_GET(world, entity, component_type) \
    ents_world_component_get(&world, entity, ENTS_COMPONENT_ID(component_type))

#define ENTS_WORLD_COMPONENT_REF(world, entity, component_type) \
    ents_world_component_ref(&world, entity, ENTS_COMPONENT_ID(component_type))

#define ENTS_WORLD_COMPONENT_REMOVE(world, entity, component_type) \
    ents_world_component_remove(&world, entity, ENTS_COMPONENT_ID(component_type))

#define ENTS_WORLD_SYSTEM_ADD(world, func, ...) \
    ents_world_system_add(&world, &(ents_system_t){ \
        .name = #func, \
        .query =  #__VA_ARGS__, \
        .callback = func \
    }) \

#endif