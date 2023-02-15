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

    void Entity::Apply() {
        for (auto component: components) {
            component->Apply(this);
        }

        for (auto entity: entities) {
            entity->Apply();
        }
    }

    void Entity::AddEntity(Entity *entity) {
        entities.emplace_back(entity);
    }

    void Entity::AddComponent(Component *component) {
        components.emplace_back(component);
    }
}

