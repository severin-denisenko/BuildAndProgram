//
// Created by Severin on 15.02.2023.
//

#include "EScene.hpp"

namespace Engine {
    void EScene::Render() {
        BeginDrawing();
        BeginMode3D(camera);
        root.Render3D();
        EndMode3D();
        root.Render2D();
        EndDrawing();
    }

    void EScene::Render3D() {
        BeginDrawing();
        BeginMode3D(camera);
        root.Render3D();
        EndMode3D();
        EndDrawing();
    }

    void EScene::Render2D() {
        BeginDrawing();
        root.Render2D();
        EndDrawing();
    }

    void EScene::Run() {
        while (!WindowShouldClose()){
            Update();
            Render();
        }
    }
} // engine