//
// Created by Severin on 19.02.2023.
//

#ifndef BUILDANDPROGRAMM_EGRID_H
#define BUILDANDPROGRAMM_EGRID_H

#include "Components/EComponent.hpp"

#include <raylib.h>

namespace Engine {

    class EGrid : public EComponent {
    public:
        EGrid(int slices, float spacing) : slices(slices), spacing(spacing) {}

        void Render3D(EEntity* entity) override{
            DrawGrid(slices, spacing);
        }

        int slices;
        float spacing;
    };

} // Engine

#endif //BUILDANDPROGRAMM_EGRID_H
