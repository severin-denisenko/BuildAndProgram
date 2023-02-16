//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_ENTITY_HPP
#define BUILDANDPROGRAMM_ENTITY_HPP

#include <vector>
#include <string>

#include "../deps/SLib/include/SLib/SLog.hpp"

#include "Components/Component.hpp"
#include "Components/Transform.hpp"

namespace engine {
    class Entity {
    public:
        Entity() = default;

        Entity(const std::string& name): name(name) {}

        void AddComponent(Component* component);;

        void AddEntity(Entity* entity);

        void Update();

        void Render2D();

        void Render3D();

        template<typename T>
        T* GetComponent(){
            for(auto component: components){
                T* val = dynamic_cast<T*>(component);

                if(val)
                    return val;
            }

            S_ERROR("Can't find requested component.");
            return nullptr;
        }

        Entity* GetChildByIndex(size_t index);

        ~Entity();

        std::string name = "default";
    private:
        std::vector<Component*> components;
        std::vector<Entity*> entities;
    };
} // engine

#endif //BUILDANDPROGRAMM_ENTITY_HPP
