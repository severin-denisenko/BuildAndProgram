//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_ESCENE_HPP
#define BUILDANDPROGRAMM_ESCENE_HPP

#include "Systems/EEntityManager.hpp"
#include "Systems/ERenderer.hpp"
#include "Systems/ECreator.hpp"
#include "Systems/EUpdater.hpp"
#include "Systems/EPhysics.hpp"
#include "EEntity.hpp"
#include "EGame.hpp"

namespace Engine {
    class EGame;

    class EScene {
    public:
        explicit EScene(std::string name);
        ~EScene();

        EEntity* root = nullptr;
        ERenderer renderer;
        EUpdater updater;
        ECreator creator;
        EPhysics physics;
        EEntityManager entityManager = EEntityManager(renderer, updater, creator, physics, *this);

        Camera3D camera3D = {{10.0f, 10.0f, 10.0f },
                           { 0.0f, 0.0f, 0.0f },
                           { 0.0f, 1.0f, 0.0f },
                           45.0f, 0 };

        Camera2D camera2D = {{0, 0}, {0, 0}, 0, 1};

        std::string name;
        bool IsActive = true;

        EGame* game = nullptr;
    };

} // engine

#endif //BUILDANDPROGRAMM_ESCENE_HPP
