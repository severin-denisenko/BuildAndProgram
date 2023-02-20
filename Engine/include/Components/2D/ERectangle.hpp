//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_ERECTANGLE_HPP
#define BUILDANDPROGRAMM_ERECTANGLE_HPP

#include "Components/EComponent.hpp"

#include "Graphics/ESprite.hpp"

namespace Engine {
    class ERectangle : public EComponent {
    public:
        explicit ERectangle(ESprite sprite) : sprite(sprite){
        }

        void Create(EEntity* entity) override{
            transform = entity->GetComponent<ETransform>();
            S_INFO("Component ERectangle created.");
        }

        void Update(EEntity* entity) override{
            if (transform == nullptr)
                S_FATAL("ETransform is null!");

            if (transform == nullptr)
                S_FATAL("ESprite is null!");
        }

        void Render2D(EEntity *entity) override{
            sprite.Render(transform->GetGlobalPosition().x, transform->GetGlobalPosition().y,
                          transform->GetGlobalScale().x, transform->GetGlobalScale().y);
        }

        ESprite sprite;
        ETransform* transform;
    };
} // engine

#endif //BUILDANDPROGRAMM_ERECTANGLE_HPP
