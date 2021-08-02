#ifndef MACRO_H
#define MACRO_H

#define ENTS_COMPONENT_ID(component_type) id_ ## component_type 

#define ENTS_WORLD_COMPONENT_REGISTER(world, component_type) \
    ents_component_type_t ENTS_COMPONENT_ID(component_type) = ents_world_component_register(&world, &(ents_component_desc_t){ \
        .data_size = sizeof(component_type), \
        .name = #component_type \
    }) \

#endif