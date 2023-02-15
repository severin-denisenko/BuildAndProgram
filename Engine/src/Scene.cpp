//
// Created by Severin on 15.02.2023.
//

#include "Scene.hpp"

namespace engine {
    void Scene::Render() {
        BeginDrawing();
        BeginMode3D(camera);
        root.Render3D();
        EndMode3D();
        root.Render2D();
        EndDrawing();
    }

    void Scene::Render3D() {
        BeginDrawing();
        BeginMode3D(camera);
        root.Render3D();
        EndMode3D();
        EndDrawing();
    }

    void Scene::Render2D() {
        BeginDrawing();
        root.Render2D();
        EndDrawing();
    }
} // engine