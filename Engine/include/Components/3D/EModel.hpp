//
// Created by Severin on 19.02.2023.
//

#ifndef BUILDANDPROGRAMM_EMODEL_HPP
#define BUILDANDPROGRAMM_EMODEL_HPP

#include "Graphics/EMesh.h"
#include "Components/EComponent.hpp"

#include <raylib.h>

namespace Engine {

    class EModel : public EComponent{
    public:
        explicit EModel(const EMesh& mesh) : mesh(mesh) {}

        void Create(EEntity* entity) override{
            transform = entity->GetComponent<ETransform>();
        }

        void Render3D(EEntity* entity) override{
            DrawModel(mesh.Get(), {transform->position.x, transform->position.y, transform->position.z}, 1.0f, WHITE);
        }

    private:
        const EMesh& mesh;
        ETransform* transform;
    };

} // Engine

#endif //BUILDANDPROGRAMM_EMODEL_HPP
