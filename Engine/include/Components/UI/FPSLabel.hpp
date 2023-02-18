//
// Created by Severin on 16.02.2023.
//

#ifndef BUILDANDPROGRAMM_FPSLABEL_HPP
#define BUILDANDPROGRAMM_FPSLABEL_HPP

#include "Components/EComponent.hpp"

#include "raylib.h"

namespace Engine {

    class FPSLabel : public EComponent{
    public:
        FPSLabel() = default;

        void Create(EEntity * entity) override{
            transform = entity->GetComponent<ETransform>();
            S_INFO("Component FPSLabel created.");
        }

        void RenderUI(EEntity * entity) override{
            if (transform == nullptr)
                S_FATAL("ETransform is null!");

            DrawFPS((int)transform->x, (int)transform->y);
        }

        ETransform* transform = nullptr;
    };

} // engine

#endif //BUILDANDPROGRAMM_FPSLABEL_HPP
