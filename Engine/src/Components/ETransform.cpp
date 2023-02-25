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


    Vector3 ETransform::GetGlobalPosition() const{
        Vector3 res = {0, 0 ,0};

        for (const EEntity* node = entity; ; node = node->GetParent()){
            if (node == nullptr)
                break;

            auto* transform = node->GetComponent<ETransform>();

            if (transform == nullptr)
                break;

            res = res * transform->scale + transform->position;
        }

        return res;
    }

    Vector3 ETransform::GetGlobalRotation() const{
        Vector3 res = {0, 0 ,0};

        for (const EEntity* node = entity; ; node = node->GetParent()){
            if (node == nullptr)
                break;

            auto* transform = node->GetComponent<ETransform>();

            if (transform == nullptr)
                break;

            res = res + transform->rotation;
        }

        return res;
    }

    Vector3 ETransform::GetGlobalScale() const{

        Vector3 res = {1, 1 ,1};

        for (const EEntity* node = entity; ; node = node->GetParent()){
            if (node == nullptr)
                break;

            auto* transform = node->GetComponent<ETransform>();

            if (transform == nullptr)
                break;

            res = res * transform->scale;
        }

        return res;
    }
}
