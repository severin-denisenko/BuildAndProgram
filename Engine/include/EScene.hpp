//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_ESCENE_HPP
#define BUILDANDPROGRAMM_ESCENE_HPP

#include "EEntity.hpp"
#include "ERenderer.hpp"
#include "EUpdater.hpp"
#include "ECreator.hpp"

namespace Engine {

    class EScene {
    public:
        EScene() = default;

        EEntity root = EEntity("Root");
        ERenderer renderer;
        EUpdater updater;
        ECreator creator;
    };

} // engine

#endif //BUILDANDPROGRAMM_ESCENE_HPP
