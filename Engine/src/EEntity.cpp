//
// Created by Severin on 15.02.2023.
//

#include "EEntity.hpp"
#include "Components/EComponent.hpp"

namespace Engine{
    void EEntity::Create() {
        for (auto& component: components) {
            component->Create(this);
        }
        created = true;
    }

    void EEntity::Render3D() {
        if(!created)
            return;

        for (auto& component: components) {
            component->Render3D(this);
        }
    }

    void EEntity::Render2D() {
        if(!created)
            return;

        for (auto& component: components) {
            component->Render2D(this);
        }
    }

    void EEntity::RenderUI() {
        if(!created)
            return;

        for (auto& component: components) {
            component->RenderUI(this);
        }
    }

    void EEntity::Update() {
        if(!created)
            return;

        for (auto& component: components) {
            component->Update(this);
        }
    }

    void EEntity::AddEntity(std::unique_ptr<EEntity> entity) {
        children.push_back(std::move(entity));
    }

    void EEntity::RemoveEntity(EEntity* entity) {
        auto found = std::find_if(
                children.begin(),
                children.end(),
                [&] (std::unique_ptr<EEntity>& p) -> bool { return p.get() == entity; }
                );

        if (found == children.end())
            S_ERROR("Entity " + entity->name + " can't be deleted from Parent!");

        children.erase(found);
    }

    void EEntity::AddComponent(std::unique_ptr<EComponent> component) {
        components.push_back(std::move(component));
    }

    EEntity *EEntity::GetChildByIndex(size_t index) {
        if(index < children.size())
            return children[index].get();
        S_ERROR("Entity by this index does not exist: " + std::to_string(index));
        return nullptr;
    }

    EEntity *EEntity::GetChildByName(const std::string& find) {
        for (auto& entity: children) {
            if (entity->name == find)
                return entity.get();
        }
        S_ERROR("Entity with this name does not exist: " + find);
        return nullptr;
    }

    size_t EEntity::GetChildCount() const {
        return children.size();
    }

    EEntity::EEntity(const std::string &name, EEntity* parent, EScene& scene) :
    name(name), created(false), scene(scene), parent(parent) {
        S_INFO("Entity " + name + " created.");
    }

    EEntity::~EEntity() {
        S_INFO("Entity " + name + " deleted.");
    }

    EScene &EEntity::GetScene() {
        return scene;
    }

    EEntity *EEntity::GetParent() const {
        if (parent == nullptr){
            S_ERROR("Returning null parent in Entity " + name + ".");
        }
        return parent;
    }
}

