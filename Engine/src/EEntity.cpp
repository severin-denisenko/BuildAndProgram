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
    }

    void EEntity::Render3D() {
        for (auto component: components) {
            component->Render3D(this);
        }

        for (auto entity: entities) {
            entity->Render3D();
        }
    }

    void EEntity::Render2D() {
        for (auto component: components) {
            component->Render2D(this);
        }

        for (auto entity: entities) {
            entity->Render2D();
        }
    }

    void EEntity::Update() {
        if(!created){
            for (auto component: components) {
                component->Create(this);
            }

            for (auto entity: entities) {
                entity->Update();
            }

            created = true;
            return;
        }

        for (auto component: components) {
            component->Update(this);
        }

        for (auto entity: entities) {
            entity->Update();
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
}

