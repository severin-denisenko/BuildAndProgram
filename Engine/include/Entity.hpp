//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_ENTITY_HPP
#define BUILDANDPROGRAMM_ENTITY_HPP

#include <vector>

#include "Component.hpp"

namespace engine {
    class Entity {
    public:
        Entity() = default;

        void AddComponent(Component* component);;

        void AddEntity(Entity* entity);

        void Apply();

        void Render2D();

        void Render3D();

        ~Entity();
    private:
        std::vector<Component*> components;
        std::vector<Entity*> entities;
    };
} // engine

#endif //BUILDANDPROGRAMM_ENTITY_HPP
