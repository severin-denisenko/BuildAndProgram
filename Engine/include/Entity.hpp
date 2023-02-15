//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_ENTITY_HPP
#define BUILDANDPROGRAMM_ENTITY_HPP

#include <vector>

#include "Components/Component.hpp"
#include "Components/Transform.hpp"

namespace engine {
    class Entity {
    public:
        Entity() = default;

        void AddComponent(Component* component);;

        void AddEntity(Entity* entity);

        virtual void Apply();

        virtual void Render2D();

        virtual void Render3D();

        template<typename T>
        T* GetComponent(){
            for(auto component: components){
                T* val = dynamic_cast<T*>(component);

                if(val)
                    return val;
            }

            return nullptr;
        }

        ~Entity();
    private:
        std::vector<Component*> components;
        std::vector<Entity*> entities;
    };
} // engine

#endif //BUILDANDPROGRAMM_ENTITY_HPP
