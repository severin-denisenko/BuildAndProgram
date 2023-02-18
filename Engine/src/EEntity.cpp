//
// Created by Severin on 15.02.2023.
//

#include "EEntity.hpp"

namespace Engine{
    EEntity::~EEntity() {
        for (auto component: components) {
            delete component;
        }

        for (auto entity: entities) {
            delete entity;
        }

        S_INFO("Entity " + name + " deleted.");
    }

    void EEntity::Render3D() {
        if(!created)
            return;

        for (auto component: components) {
            component->Render3D(this);
        }
    }

    void EEntity::Render2D() {
        if(!created)
            return;

        for (auto component: components) {
            component->Render2D(this);
        }
    }

    void EEntity::Update() {
        if(!created)
            return;

        for (auto component: components) {
            component->Update(this);
        }
    }

    void EEntity::AddEntity(EEntity *entity) {
        entities.emplace_back(entity);
    }

    void EEntity::AddComponent(EComponent *component) {
        components.emplace_back(component);
    }

    EEntity *EEntity::GetChildByIndex(size_t index) {
        if(index < entities.size())
            return entities[index];
        S_ERROR("Entity by this index does not exist: " + std::to_string(index));
        return nullptr;
    }

    EEntity *EEntity::GetChildByName(const std::string& find) {
        for (auto entity: entities) {
            if (entity->name == find)
                return entity;
        }
        S_ERROR("Entity with this name does not exist: " + find);
        return nullptr;
    }

    size_t EEntity::GetChildCount() {
        return entities.size();
    }

    EEntity::EEntity(const std::string &name, EScene& scene) : name(name), scene(scene), created(false) {
        S_INFO("Entity " + name + " created.");
    }

    void EEntity::Create() {
        for (auto component: components) {
            component->Create(this);
        }
        created = true;
    }

    EScene &EEntity::GetScene() {
        return scene;
    }
}
