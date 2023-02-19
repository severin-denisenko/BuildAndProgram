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

    Vector3 ETransform::GetGlobalPosition() {
        if (entity->name == "Root"){
            return {0, 0 ,0};
        }

        auto* transform = entity->GetPatent()->GetComponent<ETransform>();

        if(transform == nullptr){
            S_ERROR("Transform is null in GetGlobalPosition on entity " + entity->name);
            return {0, 0, 0};
        }

        return position + transform->GetGlobalPosition();
    }

    Vector3 ETransform::GetGlobalRotation() {
        if (entity->name == "Root"){
            return {0, 0 ,0};
        }

        auto* transform = entity->GetPatent()->GetComponent<ETransform>();

        if(transform == nullptr){
            S_ERROR("Transform is null in GetGlobalRotation on entity " + entity->name);
            return {0, 0, 0};
        }

        return rotation + transform->GetGlobalRotation();
    }

    Vector3 ETransform::GetGlobalScale() {
        if (entity->name == "Root"){
            return {1, 1 ,1};
        }

        auto* transform = entity->GetPatent()->GetComponent<ETransform>();

        if(transform == nullptr){
            S_ERROR("Transform is null in GetGlobalScale on entity " + entity->name);
            return {1, 1, 1};
        }

        return rotation * transform->GetGlobalScale();
    }
}
