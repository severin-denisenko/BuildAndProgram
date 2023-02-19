//
// Created by Severin on 19.02.2023.
//

#ifndef BUILDANDPROGRAMM_ECOLLIDER2D_HPP
#define BUILDANDPROGRAMM_ECOLLIDER2D_HPP

#include "Components/EComponent.hpp"
#include "raylib.h"

namespace Engine {

    class ECollider2D : public EComponent{
    public:
        enum ECollider2DShape{
            RECTANGLE,
            CIRCLE,
            TRIANGLE,
            POINT,
            LINE,
            NONE
        };

        explicit ECollider2D(ECollider2DShape shape) : shape(shape) {}

        // RECTANGLE
        Rectangle rec;

        // CIRCLE
        Vector2 center;
        float radius;

        // TRIANGLE
        Vector2 p1;
        Vector2 p2;
        Vector2 p3;

        // POINT
        Vector2 point;

        // LINE
        Vector2 l1;
        Vector2 l2;

        ECollider2DShape shape;

        bool colliding = false;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ECOLLIDER2D_HPP
