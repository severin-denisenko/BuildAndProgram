//
// Created by Severin on 18.02.2023.
//

#include "EEngine.hpp"

#include <raylib.h>

namespace Engine {
    void EEngine::Run() {
        scene.creator.Create();

        while (window.Open()){
            scene.updater.Update();
            scene.renderer.Render();
        }
    }
} // Engine