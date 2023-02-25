//
// Created by Severin on 18.02.2023.
//

#include "EGame.hpp"

#include <raylib.h>

namespace Engine {
    void EGame::Run() {
        EScene* current = scenes.front();

        while (true){
            if (!window.Open()){
                break;
            }

            if (!current->IsActive){
                scenes.pop_front();
                current = scenes.front();
            }

            current->creator.Create();
            current->updater.Update();
            current->renderer.Render(current->camera2D, current->camera3D);
            current->physics.SolvePhysics();
        }
    }

    void EGame::AddScene(EScene* scene) {
        scene->game = this;
        scenes.push_back(scene);
    }

    void EGame::LoadScene(const std::string &name) {
        for (auto s: scenes) {
            if (s->name == name){
                scenes.front()->IsActive = false;

                scenes.insert(++scenes.begin(), s);
                return;
            }
        }

        S_ERROR("Can't load scene with name: " + name);
    }
} // Engine