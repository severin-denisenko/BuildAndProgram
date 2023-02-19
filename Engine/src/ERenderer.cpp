//
// Created by Severin on 18.02.2023.
//

#include "ERenderer.hpp"
#include "EEntity.hpp"

namespace Engine {
    void ERenderer::Add2D(EEntity *entity) {
        entities2D.push_back(entity);
    }

    void ERenderer::Add3D(EEntity *entity) {
        entities3D.push_back(entity);
    }

    void ERenderer::AddUI(EEntity* entity) {
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

    void ERenderer::Remove2D(EEntity *entity) {
        auto i = std::find(entities2D.begin(), entities2D.end(), entity);
        if (i == entities2D.end()){
            S_ERROR("Entity " + entity->name + " can't be deleted from 2D Renderer!");
            return;
        }
        entities2D.erase(i);
    }

    void ERenderer::RemoveUI(EEntity *entity) {
        auto i = std::find(entitiesUI.begin(), entitiesUI.end(), entity);
        if (i == entitiesUI.end()){
            S_ERROR("Entity " + entity->name + " can't be deleted from UI Renderer!");
            return;
        }
        entitiesUI.erase(i);
    }

    void ERenderer::Remove3D(EEntity *entity) {
        auto i = std::find(entities3D.begin(), entities3D.end(), entity);
        if (i == entities3D.end()){
            S_ERROR("Entity " + entity->name + " can't be deleted from 2D Renderer!");
            return;
        }
        entities3D.erase(i);
    }
} // Engine