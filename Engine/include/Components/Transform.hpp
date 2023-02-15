//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_TRANSFORM_H
#define BUILDANDPROGRAMM_TRANSFORM_H

#include "Component.hpp"

namespace engine {
    class Transform : Component {
        float x;
        float y;
        float z;
        float rx;
        float ry;
        float rz;
    };
} // engine

#endif //BUILDANDPROGRAMM_TRANSFORM_H
