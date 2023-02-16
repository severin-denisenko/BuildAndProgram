//
// Created by Severin on 16.02.2023.
//

#ifndef BUILDANDPROGRAMM_FPSLABEL_HPP
#define BUILDANDPROGRAMM_FPSLABEL_HPP

#include "Component.hpp"

#include <raylib.h>

namespace engine {

    class FPSLabel : public Component{
    public:
        FPSLabel() = default;

        void Render2D(Entity * entity) override{
            if(!transform)
                transform = entity->GetComponent<Transform>();

            DrawFPS(transform->x, transform->y);
        }

        Transform* transform = nullptr;
    };

} // engine

#endif //BUILDANDPROGRAMM_FPSLABEL_HPP
