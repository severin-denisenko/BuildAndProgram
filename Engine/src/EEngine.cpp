//
// Created by Severin on 18.02.2023.
//

#include "EEngine.hpp"

#include <raylib.h>

namespace Engine {
    void EEngine::Run() {
        while (window.Open()){
            scene.creator.Create();
            scene.updater.Update();
            scene.renderer.Render(scene.camera2D, scene.camera3D);
            scene.physics.SolvePhysics();
        }
    }
} // Engine