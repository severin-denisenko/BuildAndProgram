//
// Created by Severin on 19.02.2023.
//

#include "EEntity.hpp"
#include "Components/ETransform.hpp"
#include <raylib.h>

namespace Engine{
    Vector3 operator+(Vector3 a, Vector3 b){
        return {a.x + b.x, a.y + b.y, a.z + b.z};
    }

    Vector3 operator*(Vector3 a, Vector3 b){
        return {a.x * b.x, a.y * b.y, a.z * b.z};
    }

    Vector2 operator+(Vector2 a, Vector3 b){
        return {a.x + b.x, a.y + b.y};
    }

    Vector2 operator*(Vector2 a, Vector3 b){
        return {a.x * b.x, a.y * b.y};
    }

    Vector2 operator+(Vector3 a, Vector2 b){
        return b + a;
    }

    Vector2 operator*(Vector3 a, Vector2 b){
        return b * a;
    }

    Rectangle operator+(Rectangle a, Vector3 b){
        return {a.x + b.x, a.y + b.y, a.width, a.height};
    }

    Rectangle operator+(Vector3 a, Rectangle b){
        return b + a;
    }

    Rectangle operator*(Rectangle a, Vector3 b){
        return {a.x, a.y, a.width * b.x, a.height * b.y};
    }

    Rectangle operator*(Vector3 a, Rectangle b){
        return b * a;
    }


    Vector3 ETransform::GetGlobalPosition() {
        if (entity == nullptr)
            return {0, 0 ,0};

        EEntity* parent = entity->GetParent();

        if (parent == nullptr){
            return {0, 0 ,0};
        }

        auto* transform = parent->GetComponent<ETransform>();

        return position * transform->GetGlobalScale() + transform->GetGlobalPosition();
    }

    Vector3 ETransform::GetGlobalRotation() {
        if (entity == nullptr)
            return {0, 0 ,0};

        EEntity* parent = entity->GetParent();

        if (parent == nullptr){
            return {0, 0 ,0};
        }

        auto* transform = entity->GetComponent<ETransform>();

        return rotation + transform->GetGlobalRotation();
    }

    Vector3 ETransform::GetGlobalScale() {
        if (entity == nullptr)
            return {1, 1 ,1};

        EEntity* parent = entity->GetParent();

        if (parent == nullptr){
            return {1, 1 ,1};
        }

        auto* transform = parent->GetComponent<ETransform>();

        return scale * transform->GetGlobalScale();
    }
}
