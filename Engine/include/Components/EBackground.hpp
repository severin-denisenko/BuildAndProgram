//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_BACKGROUND_H
#define BUILDANDPROGRAMM_BACKGROUND_H

#include "EComponent.hpp"

#include <raylib.h>

namespace engine {
    class EBackground : public EComponent {
    public:
        explicit EBackground(Color color) : color(color) {}

        void Render2D(EEntity* entity) override{
            ClearBackground(color);
        }

        Color color;
    };
} // engine

#endif //BUILDANDPROGRAMM_BACKGROUND_H
