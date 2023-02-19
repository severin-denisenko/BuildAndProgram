//
// Created by Severin on 17.02.2023.
//

#ifndef BUILDANDPROGRAMM_ERIGIDBODY_HPP
#define BUILDANDPROGRAMM_ERIGIDBODY_HPP

#include "Components/EComponent.hpp"
#include "ECollider2D.hpp"

#include "raylib.h"

namespace Engine {

    class ERigidBody : public EComponent {
    public:
        ERigidBody() = default;

        void Create(Engine::EEntity * entity) override{
            transform = entity->GetComponent<ETransform>();
            collider = entity->GetComponent<ECollider2D>();

            acceleration_y += gravity;
            S_INFO("Component ERigidBody created.");
        }

        void Update(Engine::EEntity * entity) override{
            if (transform == nullptr)
                S_FATAL("ETransform is null!");

            transform->position.x += speed_x * GetFrameTime() + acceleration_x * GetFrameTime() * GetFrameTime() / 2;
            transform->position.y += speed_y * GetFrameTime() + acceleration_y * GetFrameTime() * GetFrameTime() / 2;
            speed_x += acceleration_x * GetFrameTime();
            speed_y += acceleration_y * GetFrameTime();
        }

        float speed_x = 0;
        float speed_y = 0;
        float acceleration_x = 0;
        float acceleration_y = 0;
        float mass;
        float gravity = 98;

        ETransform *transform;
        ECollider2D *collider;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ERIGIDBODY_HPP
