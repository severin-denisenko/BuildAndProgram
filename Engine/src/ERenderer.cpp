//
// Created by Severin on 18.02.2023.
//

#include "ERenderer.hpp"

namespace Engine {
    void ERenderer::Add2D(Engine::EEntity *entity) {
        entities2D.push_back(entity);
    }

    void ERenderer::Add3D(Engine::EEntity *entity) {
        entities3D.push_back(entity);
    }

    void ERenderer::Render() {
        BeginDrawing();

        BeginMode3D(camera);
        for (auto entity: entities3D) {
            entity->Render3D();
        }
        EndMode3D();

        for (auto entity: entities2D) {
            entity->Render2D();
        }

        EndDrawing();
    }
} // Engine