//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_EENTITYFACTORY_HPP
#define BUILDANDPROGRAMM_EENTITYFACTORY_HPP

#include "EEntity.hpp"
#include "Components/EComponent.hpp"
#include "Components/ETransform.hpp"
#include "Components/UI/EText.hpp"
#include "Components/EBackground.hpp"
#include "Components/ERectangle.hpp"
#include "Components/UI/FPSLabel.hpp"
#include "Components/ERigidBody.hpp"
#include "Components/ESlideShow.h"
#include "Components/ETiling.hpp"

namespace Engine {

    class EEntityFactory {
    public:
        explicit EEntityFactory(const std::string& name, EScene& scene){
            entity = new EEntity(name, scene);

            if(entity == nullptr)
                S_FATAL("Entity is null in factory constructor!");
        };

        explicit EEntityFactory(EEntity* entity) : entity(entity) {
            if(entity == nullptr)
                S_FATAL("Entity is null in factory constructor!");
        };

        [[nodiscard]] EEntityFactory Transform() const{
            auto transform = new Engine::ETransform();
            entity->AddComponent(transform);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Transform(float x, float y) const{
            auto transform = new Engine::ETransform(x, y);
            entity->AddComponent(transform);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Transform(float x, float y, float rx, float ry) const{
            auto transform = new Engine::ETransform(x, y, rx, ry);
            entity->AddComponent(transform);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Transform(float x, float y, float rx, float ry, float sx, float sy) const{
            auto transform = new Engine::ETransform(x, y, rx, ry, sx, sy);
            entity->AddComponent(transform);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Text(const char* msg, int size, Color color) const{
            auto text = new Engine::EText(msg, size, color);
            entity->AddComponent(text);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Background(Color color) const{
            auto background = new Engine::EBackground(color);
            entity->AddComponent(background);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Rectangle(ESprite sprite) const{
            auto rectangle = new Engine::ERectangle(sprite);
            entity->AddComponent(rectangle);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory FPSLabel() const{
            auto label = new Engine::FPSLabel();
            entity->AddComponent(label);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory RigidBody() const{
            auto rigidBody = new Engine::ERigidBody();
            entity->AddComponent(rigidBody);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory SlideShow(ETileSet& tileSet) const{
            auto slideShow = new Engine::ESlideShow(tileSet);
            entity->AddComponent(slideShow);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Tiling(ETileMap& tileMap) const{
            auto tiling = new Engine::ETiling(tileMap);
            entity->AddComponent(tiling);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Add(EComponent* component) const{
            entity->AddComponent(component);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntity* Get() const{
            return entity;
        }

        EEntity* entity = nullptr;
    };

} // engine

#endif //BUILDANDPROGRAMM_EENTITYFACTORY_HPP
