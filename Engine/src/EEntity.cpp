//
// Created by Severin on 15.02.2023.
//

#include "EEntity.hpp"

namespace Engine{
    void EEntity::Create() {
        for (auto component: components) {
            component->Create(this);
        }
        created = true;
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

    void EEntity::RenderUI() {
        if(!created)
            return;

        for (auto component: components) {
            component->RenderUI(this);
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

    void EEntity::RemoveEntity(EEntity* entity) {
        auto i = std::find(entities.begin(), entities.end(), entity);
        if (i == entities.end())
            S_ERROR("Entity " + entity->name + " can't be deleted from Parent!");
        entities.erase(i);
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

    size_t EEntity::GetChildCount() const {
        return entities.size();
    }

    EEntity::EEntity(const std::string &name, EEntity* parent, EScene& scene) :
    name(name), created(false), scene(scene), parent(parent) {
        S_INFO("Entity " + name + " created.");
    }

    EEntity::~EEntity() {
        for (auto component: components) {
            delete component;
        }

        S_INFO("Entity " + name + " deleted.");
    }

    EScene &EEntity::GetScene() {
        return scene;
    }

    EEntity *EEntity::GetPatent() const {
        return parent;
    }
}

