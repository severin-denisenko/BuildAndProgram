//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_EENTITY_HPP
#define BUILDANDPROGRAMM_EENTITY_HPP

#include <vector>
#include <string>

#include "../deps/SLib/include/SLib/SLog.hpp"

namespace Engine {
    class EScene;
    class EComponent;

    class EEntity {
    public:
        EEntity(const std::string& name, EEntity* parent, EScene& scene);
        ~EEntity();

        void AddComponent(std::unique_ptr<EComponent> component);;
        void AddEntity(std::unique_ptr<EEntity> entity);
        void RemoveEntity(EEntity* entity);

        EEntity* GetChildByIndex(size_t index);
        [[nodiscard]] size_t GetChildCount() const;
        EEntity* GetChildByName(const std::string& name);

        [[nodiscard]] EEntity* GetParent() const;

        EScene& GetScene();

        void Update();
        void Create();
        void Render2D();
        void Render3D();
        void RenderUI();

        template<typename T>
        T* GetComponent(){
            for(auto& component: components){
                T* val = dynamic_cast<T*>(component.get());

                if(val)
                    return val;
            }

            S_ERROR("Can't find component with type: " + std::string(typeid(T).name()));
            return nullptr;
        }

        std::string name = "Default";
        std::vector<std::unique_ptr<EEntity>> children;
        std::vector<std::unique_ptr<EComponent>> components;
        bool created;
    private:
        EScene& scene;
        EEntity* parent = nullptr;
    };
} // engine

#endif //BUILDANDPROGRAMM_EENTITY_HPP
