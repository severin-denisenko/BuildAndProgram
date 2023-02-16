//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_EENTITYFACTORY_H
#define BUILDANDPROGRAMM_EENTITYFACTORY_H

#include "EEntity.hpp"
#include "Components/EComponent.hpp"
#include "Components/ETransform.hpp"
#include "Components/EText.hpp"
#include "Components/EBackground.hpp"
#include "Components/ESprite.hpp"
#include "Components/FPSLabel.hpp"

namespace engine {

    class EEntityFactory {
    public:
        EEntityFactory(){
            entity = new EEntity();
        };

        explicit EEntityFactory(const std::string& name){
            entity = new EEntity(name);
        };

        EEntityFactory(EEntity* entity) : entity(entity) {};

        EEntityFactory Transform(){
            auto transform = new engine::ETransform();
            entity->AddComponent(transform);
            return {entity};
        }

        EEntityFactory Transform(float x, float y){
            auto transform = new engine::ETransform(x, y);
            entity->AddComponent(transform);
            return {entity};
        }

        EEntityFactory Transform(float x, float y, float rx, float ry){
            auto transform = new engine::ETransform(x, y, rx, ry);
            entity->AddComponent(transform);
            return {entity};
        }

        EEntityFactory Transform(float x, float y, float rx, float ry, float sx, float sy){
            auto transform = new engine::ETransform(x, y, rx, ry, sx, sy);
            entity->AddComponent(transform);
            return {entity};
        }

        EEntityFactory Text(const char* msg, int size, Color color){
            auto text = new engine::EText(msg, size, color);
            entity->AddComponent(text);
            return {entity};
        }

        EEntityFactory Background(Color color){
            auto background = new engine::EBackground(color);
            entity->AddComponent(background);
            return {entity};
        }

        EEntityFactory Sprite(const char* filename){
            auto sprite = new engine::ESprite(filename);
            entity->AddComponent(sprite);
            return {entity};
        }

        EEntityFactory Sprite(const char* filename, Color color){
            auto sprite = new engine::ESprite(filename, color);
            entity->AddComponent(sprite);
            return {entity};
        }

        EEntityFactory FPSLabel(){
            auto label = new engine::FPSLabel();
            entity->AddComponent(label);
            return {entity};
        }

        EEntityFactory Add(EComponent* component){
            entity->AddComponent(component);
            return {entity};
        }

        EEntity* Get(){
            return entity;
        }

        EEntity* entity;
    };

} // engine

#endif //BUILDANDPROGRAMM_EENTITYFACTORY_H
