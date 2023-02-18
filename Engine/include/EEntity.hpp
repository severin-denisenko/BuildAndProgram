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
    class EScene;

    class EEntity {
    public:
        EEntity(const std::string& name, EScene& scene);

        void AddComponent(EComponent* component);;

        void AddEntity(EEntity* entity);
        void RemoveEntity(EEntity* entity);

        void Update();

        void Create();

        void Render2D();

        void Render3D();

        void RenderUI();

        template<typename T>
        T* GetComponent(){
            for(auto component: components){
                T* val = dynamic_cast<T*>(component);

                if(val)
                    return val;
            }

            S_ERROR("Can't find component with type: " + std::string(typeid(T).name()));
            return nullptr;
        }

        EEntity* GetChildByIndex(size_t index);
        size_t GetChildCount();

        EEntity* GetChildByName(const std::string& name);
        EScene& GetScene();

        ~EEntity();

        std::string name = "default";
        Engine::EScene& scene;
    private:
        bool created;
        std::vector<EComponent*> components;
        std::vector<EEntity*> entities;
    };
} // engine

#endif //BUILDANDPROGRAMM_EENTITY_HPP
