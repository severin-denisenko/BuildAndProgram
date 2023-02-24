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
            entity->AddComponent(std::make_unique<ETransform>());
            return *this;
        }

        [[nodiscard]] EEntityFactory& Transform(float x, float y){
            entity->AddComponent(std::make_unique<ETransform>(x, y));
            return *this;
        }

        [[nodiscard]] EEntityFactory& Transform(float x, float y, float rx, float ry){
            entity->AddComponent(std::make_unique<ETransform>(x, y, rx, ry));
            return *this;
        }

        [[nodiscard]] EEntityFactory& Transform(float x, float y, float z){
            entity->AddComponent(std::make_unique<ETransform>(x, y, z));
            return *this;
        }

        [[nodiscard]] EEntityFactory& Transform(float x, float y, float rx, float ry, float sx, float sy){
            entity->AddComponent(std::make_unique<ETransform>(x, y, rx, ry, sx, sy));
            return *this;
        }

        [[nodiscard]] EEntityFactory& Text(const char* msg, int size, Color color){
            entity->AddComponent(std::make_unique<EText>(msg, size, color));
            return *this;
        }

        [[nodiscard]] EEntityFactory& Background(Color color){
            entity->AddComponent(std::make_unique<EBackground>(color));
            return *this;
        }

        [[nodiscard]] EEntityFactory& Rectangle(ESprite sprite){
            entity->AddComponent(std::make_unique<ERectangle>(sprite));
            return *this;
        }

        [[nodiscard]] EEntityFactory& FPSLabel(){
            entity->AddComponent(std::make_unique<Engine::FPSLabel>());
            return *this;
        }

        [[nodiscard]] EEntityFactory& RigidBody(){
            entity->AddComponent(std::make_unique<ERigidBody>());
            return *this;
        }

        [[nodiscard]] EEntityFactory& SlideShow(ETileSet& tileSet){
            entity->AddComponent(std::make_unique<ESlideShow>(tileSet));
            return *this;
        }

        [[nodiscard]] EEntityFactory& Tiling(ETileMap& tileMap){
            entity->AddComponent(std::make_unique<ETiling>(tileMap));
            return *this;
        }

        [[nodiscard]] EEntityFactory& Model(EMesh mesh){
            entity->AddComponent(std::make_unique<EModel>(mesh));
            return *this;
        }

        [[nodiscard]] EEntityFactory& Grid(int slices, float spacing){
            entity->AddComponent(std::make_unique<EGrid>(slices, spacing));
            return *this;
        }

        [[nodiscard]] EEntityFactory& CameraController3D(){
            entity->AddComponent(std::make_unique<ECameraController3D>());
            return *this;
        }

        [[nodiscard]] EEntityFactory& Collider2D(ECollider2D::ECollider2DShape shape){
            entity->AddComponent(std::make_unique<ECollider2D>(shape));
            return *this;
        }

        [[nodiscard]] EEntityFactory& Button(ETileSet& tileSet){
            entity->AddComponent(std::make_unique<EButton>(tileSet));
            return *this;
        }

        [[nodiscard]] EEntityFactory& Add(EComponent* component){
            entity->AddComponent(std::unique_ptr<EComponent>(component));
            return *this;
        }

        [[nodiscard]] EEntity* Get() const{
            return entity;
        }

        EEntity* entity = nullptr;
    };

} // engine

#endif //BUILDANDPROGRAMM_EENTITYFACTORY_HPP
