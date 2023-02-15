//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_TRANSFORM_H
#define BUILDANDPROGRAMM_TRANSFORM_H

#include "Component.hpp"

namespace engine {
    class Transform : public Component {
    public:
        Transform() = default;

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
