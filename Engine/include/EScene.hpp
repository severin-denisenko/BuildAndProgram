//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_ESCENE_HPP
#define BUILDANDPROGRAMM_ESCENE_HPP

#include "Systems/EEntityManager.hpp"
#include "Systems/ERenderer.hpp"
#include "Systems/ECreator.hpp"
#include "Systems/EUpdater.hpp"
#include "EEntity.hpp"

namespace Engine {

    class EScene {
    public:
        EScene();

        EEntity* root;
        ERenderer renderer;
        EUpdater updater;
        ECreator creator;
        EEntityManager entityManager = EEntityManager(renderer, updater, creator, *this);

        Camera3D camera3D = {{5.0f, 5.0f, 5.0f },
                           { 0.0f, 0.0f, 0.0f },
                           { 0.0f, 1.0f, 0.0f },
                           45.0f, 0 };

        Camera2D camera2D = {{0, 0}, {0, 0}, 0, 1};
    };

} // engine

#endif //BUILDANDPROGRAMM_ESCENE_HPP
