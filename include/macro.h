#ifndef MACRO_H
#define MACRO_H

#define ENTS_ID_COMPONENT(component_type) id_ ## component_type 

#define ENTS_WORLD_REGISTER_COMPONENT(world, component_type) \
    uint64_t ENTS_ID_COMPONENT(component_type) = ents_world_register_component(&world, &(ents_component_desc_t){ \
        .data_size = sizeof(component_type), \
        .name = #component_type \
    }) \

#define ENTS_WORLD_SET_COMPONENT(world, entity, component_type, ...) \
    ents_world_set_component(&world, entity, ENTS_ID_COMPONENT(component_type), &(component_type)__VA_ARGS__)

#define ENTS_WORLD_GET_COMPONENT(world, entity, component_type) \
    ents_world_get_component(&world, entity, ENTS_ID_COMPONENT(component_type))

#define ENTS_WORLD_REF_COMPONENT(world, entity, component_type) \
    ents_world_ref_component(&world, entity, ENTS_ID_COMPONENT(component_type))

#define ENTS_WORLD_REMOVE_COMPONENT(world, entity, component_type) \
    ents_world_remove_component(&world, entity, ENTS_ID_COMPONENT(component_type))

#define ENTS_WORLD_ADD_SYSTEM(world, func, ...) \
    ents_scheduler_add_system(&scheduler, &(ents_system_t){ \
        .query =  #__VA_ARGS__, \
        .callback = func \
    }) \

#endif