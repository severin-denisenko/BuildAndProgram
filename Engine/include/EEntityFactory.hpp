//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_EENTITYFACTORY_HPP
#define BUILDANDPROGRAMM_EENTITYFACTORY_HPP

#include "EEntity.hpp"

#include "Components/EComponent.hpp"
#include "Components/ETransform.hpp"
#include "Components/ERigidBody.hpp"
#include "Components/ECameraController3D.hpp"

#include "Components/UI/EText.hpp"
#include "Components/UI/FPSLabel.hpp"

#include "Components/2D/EBackground.hpp"
#include "Components/2D/ERectangle.hpp"
#include "Components/2D/ESlideShow.h"
#include "Components/2D/ETiling.hpp"

#include "Components/3D/EModel.hpp"
#include "Components/3D/EGrid.h"

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
            auto transform = new ETransform();
            entity->AddComponent(transform);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Transform(float x, float y) const{
            auto transform = new ETransform(x, y);
            entity->AddComponent(transform);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Transform(float x, float y, float rx, float ry) const{
            auto transform = new ETransform(x, y, rx, ry);
            entity->AddComponent(transform);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Transform(float x, float y, float z) const{
            auto transform = new ETransform(x, y, z);
            entity->AddComponent(transform);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Transform(float x, float y, float rx, float ry, float sx, float sy) const{
            auto transform = new ETransform(x, y, rx, ry, sx, sy);
            entity->AddComponent(transform);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Text(const char* msg, int size, Color color) const{
            auto text = new EText(msg, size, color);
            entity->AddComponent(text);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Background(Color color) const{
            auto background = new EBackground(color);
            entity->AddComponent(background);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Rectangle(ESprite sprite) const{
            auto rectangle = new ERectangle(sprite);
            entity->AddComponent(rectangle);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory FPSLabel() const{
            auto label = new Engine::FPSLabel();
            entity->AddComponent(label);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory RigidBody() const{
            auto rigidBody = new ERigidBody();
            entity->AddComponent(rigidBody);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory SlideShow(ETileSet& tileSet) const{
            auto slideShow = new ESlideShow(tileSet);
            entity->AddComponent(slideShow);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Tiling(ETileMap& tileMap) const{
            auto tiling = new ETiling(tileMap);
            entity->AddComponent(tiling);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Model(EMesh mesh) const{
            auto model = new EModel(mesh);
            entity->AddComponent(model);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory Grid(int slices, float spacing) const{
            auto grid = new EGrid(slices, spacing);
            entity->AddComponent(grid);
            return EEntityFactory(entity);
        }

        [[nodiscard]] EEntityFactory CameraController3D() const{
            auto controller = new ECameraController3D();
            entity->AddComponent(controller);
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
