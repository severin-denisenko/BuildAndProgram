//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_ENTITYFACTORY_H
#define BUILDANDPROGRAMM_ENTITYFACTORY_H

#include "Entity.hpp"
#include "Components/Component.hpp"
#include "Components/Transform.hpp"
#include "Components/Text.hpp"
#include "Components/Background.hpp"
#include "Components/Sprite.hpp"

namespace engine {

    class EntityFactory {
    public:
        EntityFactory(){
            entity = new Entity();
        };

        explicit EntityFactory(const std::string& name){
            entity = new Entity(name);
        };

        EntityFactory(Entity* entity) : entity(entity) {};

        EntityFactory Transform(){
            auto transform = new engine::Transform();
            entity->AddComponent(transform);
            return {entity};
        }

        EntityFactory Transform(float x, float y){
            auto transform = new engine::Transform(x, y);
            entity->AddComponent(transform);
            return {entity};
        }

        EntityFactory Transform(float x, float y, float rx, float ry){
            auto transform = new engine::Transform(x, y, rx, ry);
            entity->AddComponent(transform);
            return {entity};
        }

        EntityFactory Transform(float x, float y, float rx, float ry, float sx, float sy){
            auto transform = new engine::Transform(x, y, rx, ry, sx, sy);
            entity->AddComponent(transform);
            return {entity};
        }

        EntityFactory Text(const char* msg, int size, Color color){
            auto text = new engine::Text(msg, size, color);
            entity->AddComponent(text);
            return {entity};
        }

        EntityFactory Background(Color color){
            auto background = new engine::Background(color);
            entity->AddComponent(background);
            return {entity};
        }

        EntityFactory Sprite(const char* filename){
            auto sprite = new engine::Sprite(filename);
            entity->AddComponent(sprite);
            return {entity};
        }

        Entity* Get(){
            return entity;
        }

        Entity* entity;
    };

} // engine

#endif //BUILDANDPROGRAMM_ENTITYFACTORY_H
