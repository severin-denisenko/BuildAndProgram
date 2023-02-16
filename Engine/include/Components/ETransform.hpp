//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_TRANSFORM_H
#define BUILDANDPROGRAMM_TRANSFORM_H

#include "EComponent.hpp"

namespace Engine {
    class ETransform : public EComponent {
    public:
        ETransform() = default;

        ETransform(float x, float y) : x(x), y(y) {}
        ETransform(float x, float y, float rx, float ry) : x(x), y(y), rx(rx), ry(ry) {}
        ETransform(float x, float y, float rx, float ry, float sx, float sy) : x(x), y(y),
                                                                               rx(rx), ry(ry), sx(sx), sy(sy) {}

        float x = 0;
        float y = 0;
        float z = 0;
        float rx = 0;
        float ry = 0;
        float rz = 0;
        float sx = 1;
        float sy = 1;
        float sz = 1;
    };
} // engine

#endif //BUILDANDPROGRAMM_TRANSFORM_H
