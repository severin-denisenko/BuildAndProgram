//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_EENTITYFACTORY_HPP
#define BUILDANDPROGRAMM_EENTITYFACTORY_HPP

#include "EEntity.hpp"

#include "Components/EComponent.hpp"
#include "Components/ETransform.hpp"
#include "Components/Physics/ERigidBody.hpp"
#include "Components/ECameraController3D.hpp"
#include "Components/Physics/ECollider2D.hpp"

#include "Components/UI/EText.hpp"
#include "Components/UI/FPSLabel.hpp"
#include "Components/UI/EButton.hpp"

#include "Components/2D/EBackground.hpp"
#include "Components/2D/ERectangle.hpp"
#include "Components/2D/ESlideShow.hpp"
#include "Components/2D/ETiling.hpp"

#include "Components/3D/EModel.hpp"
#include "Components/3D/EGrid.h"

namespace Engine {

    class EEntityFactory {
    public:
        explicit EEntityFactory(const std::string& name, EEntity* parent, EScene& scene){
            entity = new EEntity(name, parent, scene);

            if(entity == nullptr)
                S_FATAL("Entity is null in factory constructor!");
        };

        [[nodiscard]] EEntityFactory& Transform(){
            auto transform = new ETransform();
            entity->AddComponent(transform);
            return *this;
        }

        [[nodiscard]] EEntityFactory& Transform(float x, float y){
            auto transform = new ETransform(x, y);
            entity->AddComponent(transform);
            return *this;
        }

        [[nodiscard]] EEntityFactory& Transform(float x, float y, float rx, float ry){
            auto transform = new ETransform(x, y, rx, ry);
            entity->AddComponent(transform);
            return *this;
        }

        [[nodiscard]] EEntityFactory& Transform(float x, float y, float z){
            auto transform = new ETransform(x, y, z);
            entity->AddComponent(transform);
            return *this;
        }

        [[nodiscard]] EEntityFactory& Transform(float x, float y, float rx, float ry, float sx, float sy){
            auto transform = new ETransform(x, y, rx, ry, sx, sy);
            entity->AddComponent(transform);
            return *this;
        }

        [[nodiscard]] EEntityFactory& Text(const char* msg, int size, Color color){
            auto text = new EText(msg, size, color);
            entity->AddComponent(text);
            return *this;
        }

        [[nodiscard]] EEntityFactory& Background(Color color){
            auto background = new EBackground(color);
            entity->AddComponent(background);
            return *this;
        }

        [[nodiscard]] EEntityFactory& Rectangle(ESprite sprite){
            auto rectangle = new ERectangle(sprite);
            entity->AddComponent(rectangle);
            return *this;
        }

        [[nodiscard]] EEntityFactory& FPSLabel(){
            auto label = new Engine::FPSLabel();
            entity->AddComponent(label);
            return *this;
        }

        [[nodiscard]] EEntityFactory& RigidBody(){
            auto rigidBody = new ERigidBody();
            entity->AddComponent(rigidBody);
            return *this;
        }

        [[nodiscard]] EEntityFactory& SlideShow(ETileSet& tileSet){
            auto slideShow = new ESlideShow(tileSet);
            entity->AddComponent(slideShow);
            return *this;
        }

        [[nodiscard]] EEntityFactory& Tiling(ETileMap& tileMap){
            auto tiling = new ETiling(tileMap);
            entity->AddComponent(tiling);
            return *this;
        }

        [[nodiscard]] EEntityFactory& Model(EMesh mesh){
            auto model = new EModel(mesh);
            entity->AddComponent(model);
            return *this;
        }

        [[nodiscard]] EEntityFactory& Grid(int slices, float spacing){
            auto grid = new EGrid(slices, spacing);
            entity->AddComponent(grid);
            return *this;
        }

        [[nodiscard]] EEntityFactory& CameraController3D(){
            auto controller = new ECameraController3D();
            entity->AddComponent(controller);
            return *this;
        }

        [[nodiscard]] EEntityFactory& Collider2D(ECollider2D::ECollider2DShape shape){
            auto controller = new ECollider2D(shape);
            entity->AddComponent(controller);
            return *this;
        }

        [[nodiscard]] EEntityFactory& Button(ETileSet& tileSet){
            auto button = new EButton(tileSet);
            entity->AddComponent(button);
            return *this;
        }

        [[nodiscard]] EEntityFactory& Add(EComponent* component){
            entity->AddComponent(component);
            return *this;
        }

        [[nodiscard]] EEntity* Get() const{
            return entity;
        }

        EEntity* entity = nullptr;
    };

} // engine

#endif //BUILDANDPROGRAMM_EENTITYFACTORY_HPP
