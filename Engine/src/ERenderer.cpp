//
// Created by Severin on 18.02.2023.
//

#include "ERenderer.hpp"
#include "EEntity.hpp"

namespace Engine {
    void ERenderer::Add2D(Engine::EEntity *entity) {
        entities2D.push_back(entity);
    }

    void ERenderer::Add3D(Engine::EEntity *entity) {
        entities3D.push_back(entity);
    }

    void ERenderer::AddUI(Engine::EEntity* entity) {
        entitiesUI.push_back(entity);
    }

    void ERenderer::Render(Camera2D& camera2D, Camera3D& camera3D) {
        BeginDrawing();

        BeginMode3D(camera3D);
        for (auto entity: entities3D) {
            entity->Render3D();
        }
        EndMode3D();

        BeginMode2D(camera2D);
        for (auto entity: entities2D) {
            entity->Render2D();
        }
        EndMode2D();

        for (auto entity: entitiesUI) {
            entity->RenderUI();
        }

        EndDrawing();
    }

    ERenderer::ERenderer() {
    }
} // Engine