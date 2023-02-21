//
// Created by Severin on 18.02.2023.
//

#include "Systems/ERenderer.hpp"
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

        BeginTextureMode(gameView2D);
        BeginMode2D(camera2D);
        for (auto entity: entities2D) {
            entity->Render2D();
        }
        EndMode2D();
        EndTextureMode();

        Rectangle source = {0.0f, 0.0f, (float)gameView2D.texture.width, (float)-gameView2D.texture.height };
        Rectangle dist = { 0, 0 , (float)GetScreenWidth(), (float)GetScreenHeight()};

        if(preserveAspectRatio){
            float scale = std::min((float)GetScreenWidth() / (float)gameView2D.texture.width,
                                   (float)GetScreenHeight() / (float)gameView2D.texture.height);

            dist = { ((float)GetScreenWidth() - ((float)gameView2D.texture.width * scale)) * 0.5f,
                     ((float)GetScreenHeight() - ((float)gameView2D.texture.height * scale)) * 0.5f,
                     (float)gameView2D.texture.width * scale,
                     (float)gameView2D.texture.height * scale };
        }

        DrawTexturePro(gameView2D.texture, source,dist,{0, 0}, 0.0f, WHITE);

        BeginMode3D(camera3D);
        for (auto entity: entities3D) {
            entity->Render3D();
        }
        EndMode3D();

        for (auto entity: entitiesUI) {
            entity->RenderUI();
        }

        EndDrawing();
    }

    ERenderer::ERenderer(int width, int height){
        gameView2D = LoadRenderTexture(width, height);
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

    ERenderer::~ERenderer() {
        UnloadRenderTexture(gameView2D);
    }
} // Engine