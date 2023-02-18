//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_ERECTANGLE_HPP
#define BUILDANDPROGRAMM_ERECTANGLE_HPP

#include "EComponent.hpp"

#include "ESprite.hpp"

namespace Engine {
    class ERectangle : public EComponent {
    public:
        explicit ERectangle(ESprite sprite) : sprite(sprite){
        }

        void Create(EEntity* entity) override{
            transform = entity->GetComponent<ETransform>();
            S_INFO("Component ERectangle created");

        }

        void Update(EEntity* entity) override{
            sprite.destination.x = transform->x;
            sprite.destination.y = transform->y;
            sprite.destination.height = sprite.source.height * transform->sx;
            sprite.destination.width = sprite.source.width * transform->sy;
            sprite.rotation = transform->rz;
        }

        void Render2D(EEntity *entity) override{
            sprite.Render();
        }

        Engine::ESprite sprite;
        Engine::ETransform* transform;
    };
} // engine

#endif //BUILDANDPROGRAMM_ERECTANGLE_HPP
