//
// Created by Severin on 15.02.2023.
//

#include "Entity.hpp"

namespace engine{
    Entity::~Entity() {
        for (auto component: components) {
            delete component;
        }

        for (auto entity: entities) {
            delete entity;
        }
    }

    void Entity::Render3D() {
        for (auto component: components) {
            component->Render3D(this);
        }

        for (auto entity: entities) {
            entity->Render3D();
        }
    }

    void Entity::Render2D() {
        for (auto component: components) {
            component->Render2D(this);
        }

        for (auto entity: entities) {
            entity->Render2D();
        }
    }

    void Entity::Update() {
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

    void Entity::AddEntity(Entity *entity) {
        entities.emplace_back(entity);
    }

    void Entity::AddComponent(Component *component) {
        components.emplace_back(component);
    }

    Entity *Entity::GetChildByIndex(size_t index) {
        if(index < entities.size())
            return entities[index];
        S_ERROR("Entity by this index does not exist: " + std::to_string(index));
        return nullptr;
    }

    Entity *Entity::GetChildByName(const std::string& find) {

        for (auto entity: entities) {
            if (entity->name == find)
                return entity;
        }

        S_ERROR("Entity with this name does not exist: " + find);
        return nullptr;
    }
}

