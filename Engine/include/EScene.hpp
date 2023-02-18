//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_ESCENE_HPP
#define BUILDANDPROGRAMM_ESCENE_HPP

#include "ERenderer.hpp"
#include "ECreator.hpp"
#include "EUpdater.hpp"
#include "EEntity.hpp"

namespace Engine {

    class EScene {
    public:
        EScene();

        Engine::EEntity* root;
        Engine::ERenderer renderer;
        Engine::EUpdater updater;
        Engine::ECreator creator;

        Camera3D camera3D = {{5.0f, 5.0f, 5.0f },
                           { 0.0f, 0.0f, 0.0f },
                           { 0.0f, 1.0f, 0.0f },
                           45.0f, 0 };

        Camera2D camera2D = {{0, 0}, {0, 0}, 0, 1};
    };

} // engine

#endif //BUILDANDPROGRAMM_ESCENE_HPP
