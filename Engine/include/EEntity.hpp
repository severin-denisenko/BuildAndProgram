//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_EENTITY_HPP
#define BUILDANDPROGRAMM_EENTITY_HPP

#include <vector>
#include <string>

#include "../deps/SLib/include/SLib/SLog.hpp"

#include "Components/EComponent.hpp"
#include "Components/ETransform.hpp"

namespace Engine {
    class EEntity {
    public:
        EEntity() = default;

        EEntity(const std::string& name): name(name) {}

        void AddComponent(EComponent* component);;

        void AddEntity(EEntity* entity);

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

        EEntity* GetChildByIndex(size_t index);
        size_t GetChildCount();

        EEntity* GetChildByName(const std::string& name);

        ~EEntity();

        std::string name = "default";
    private:
        bool created  = false;
        std::vector<EComponent*> components;
        std::vector<EEntity*> entities;
    };
} // engine

#endif //BUILDANDPROGRAMM_EENTITY_HPP
