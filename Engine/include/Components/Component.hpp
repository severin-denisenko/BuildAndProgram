//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_COMPONENT_HPP
#define BUILDANDPROGRAMM_COMPONENT_HPP

#include "Entity.hpp"

namespace engine {
    class Entity;

    class Component {
    public:
        virtual void Apply(Entity* entity) {};
        virtual void Render2D(Entity* entity) {};
        virtual void Render3D(Entity* entity) {};

        virtual ~Component() = default;
    };
} // engine

#endif //BUILDANDPROGRAMM_COMPONENT_HPP
