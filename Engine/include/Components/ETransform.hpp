//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_TRANSFORM_H
#define BUILDANDPROGRAMM_TRANSFORM_H

#include "EEntity.hpp"
#include "EComponent.hpp"
#include <raylib.h>

namespace Engine {
    Vector3 operator+(Vector3 a, Vector3 b);
    Vector3 operator*(Vector3 a, Vector3 b);
    Vector2 operator+(Vector2 a, Vector3 b);
    Vector2 operator*(Vector2 a, Vector3 b);
    Vector2 operator+(Vector3 a, Vector2 b);
    Vector2 operator*(Vector3 a, Vector2 b);
    Rectangle operator+(Vector3 a, Rectangle b);
    Rectangle operator+(Rectangle a, Vector3 b);
    Rectangle operator*(Vector3 a, Rectangle b);
    Rectangle operator*(Rectangle a, Vector3 b);

    class ETransform : public EComponent {
    public:
        ETransform() = default;

        void Create(EEntity* e) override{
            this->entity = e;
        }

        Vector3 GetGlobalPosition();
        Vector3 GetGlobalRotation();
        Vector3 GetGlobalScale();

        ETransform(float x, float y) : position({x, y, 0}) {}
        ETransform(float x, float y, float rx, float ry) : position({x, y, 0}), rotation({rx, ry, 0}) {}
        ETransform(float x, float y, float rx, float ry, float sx, float sy) : position({x, y, 0}),
        rotation({rx, ry, 0}), scale({sx, sy, 1}) {}
        ETransform(float x, float y, float z) : position({x, y, z}) {}
        ETransform(float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz) :
        position({x, y, z}), rotation({rx, ry, rz}), scale({sx, sy, sz}) {}

        Vector3 position = {0, 0, 0};
        Vector3 rotation = {0, 0, 0};
        Vector3 scale = {1, 1, 1};
    private:
        EEntity* entity = nullptr;
    };
} // engine

#endif //BUILDANDPROGRAMM_TRANSFORM_H
