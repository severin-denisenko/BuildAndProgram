//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_EENGINE_HPP
#define BUILDANDPROGRAMM_EENGINE_HPP

#include "EScene.hpp"
#include "EWindow.hpp"

namespace Engine {

    class EEngine {
    public:
        explicit EEngine(Engine::EScene& scene, Engine::EWindow& window) : scene(scene), window(window) {}

        void Run();

    private:
        Engine::EScene& scene;
        Engine::EWindow& window;
    };

} // Engine

#endif //BUILDANDPROGRAMM_EENGINE_HPP
