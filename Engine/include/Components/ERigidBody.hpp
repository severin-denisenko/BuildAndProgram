//
// Created by Severin on 17.02.2023.
//

#ifndef BUILDANDPROGRAMM_ERIGIDBODY_HPP
#define BUILDANDPROGRAMM_ERIGIDBODY_HPP

#include "EComponent.hpp"

#include <raylib.h>

namespace Engine {

    class ERigidBody : public EComponent {
    public:
        ERigidBody() = default;

        void Create(Engine::EEntity * entity) override{
            transform = entity->GetComponent<Engine::ETransform>();

            acceleration_y = gravity;
            S_INFO("Component ERigidBody created.");
        }

        void Update(Engine::EEntity * entity) override{
            if (transform == nullptr)
                S_FATAL("ETransform is null!");

            transform->x += speed_x * GetFrameTime() + acceleration_x * GetFrameTime() * GetFrameTime() / 2;
            transform->y += speed_y * GetFrameTime() + acceleration_y * GetFrameTime() * GetFrameTime() / 2;
            speed_x += acceleration_x * GetFrameTime();
            speed_y += acceleration_y * GetFrameTime();
        }

        float speed_x = 0;
        float speed_y = 0;
        float acceleration_x = 0;
        float acceleration_y = 0;
        float mass;
        float gravity = 98;

        Engine::ETransform *transform;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ERIGIDBODY_HPP
