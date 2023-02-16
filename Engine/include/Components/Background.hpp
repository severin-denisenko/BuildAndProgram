//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_BACKGROUND_H
#define BUILDANDPROGRAMM_BACKGROUND_H

#include "Component.hpp"

#include <raylib.h>

namespace engine {
    class Background : public Component {
    public:
        explicit Background(Color color) : color(color) {}

        void Render2D(Entity* entity) override{
            ClearBackground(color);
        }

        Color color;
    };
} // engine

#endif //BUILDANDPROGRAMM_BACKGROUND_H
