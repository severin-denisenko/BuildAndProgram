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
    };

} // engine

#endif //BUILDANDPROGRAMM_ESCENE_HPP
