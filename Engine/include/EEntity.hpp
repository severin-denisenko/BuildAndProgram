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
    class EComponent;

    class EEntity {
    public:
        EEntity(const std::string& name, EScene& scene);
        ~EEntity();

        void AddComponent(EComponent* component);;
        void AddEntity(EEntity* entity);
        void RemoveEntity(EEntity* entity);

        EEntity* GetChildByIndex(size_t index);
        size_t GetChildCount() const;
        EEntity* GetChildByName(const std::string& name);

        EScene& GetScene();

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

        std::string name = "Default";
        std::vector<EEntity*> entities;
    private:
        bool created;
        Engine::EScene& scene;
        std::vector<EComponent*> components;
    };
} // engine

#endif //BUILDANDPROGRAMM_EENTITY_HPP
