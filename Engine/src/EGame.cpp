//
// Created by Severin on 18.02.2023.
//

#include "EGame.hpp"

#include <raylib.h>

namespace Engine {
    void EGame::Run() {
        while (!scenes.empty()){
            RunScene(scenes.front());
            scenes.pop_front();
        }
    }

    void EGame::RunScene(EScene* scene) {
        while (scene->IsActive){
            if (!window.Open()){
                break;
            }

            scene->creator.Create();
            scene->updater.Update();
            scene->renderer.Render(scene->camera2D, scene->camera3D);
            scene->physics.SolvePhysics();
        }
    }

    void EGame::AddScene(EScene* scene) {
        scenes.push_back(scene);
    }
} // Engine