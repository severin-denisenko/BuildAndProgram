//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_SCENE_HPP
#define BUILDANDPROGRAMM_SCENE_HPP

#include "Entity.hpp"

#include <raylib.h>

namespace engine {

    class Scene {
    public:
        Scene() = default;

        void Update(){
            root.Update();
        }

        void Render2D();;

        void Render3D();

        void Render();

        void Run();

        Camera camera = { { 5.0f, 5.0f, 5.0f },
                          { 0.0f, 0.0f, 0.0f },
                          { 0.0f, 1.0f, 0.0f },
                          45.0f, 0 };;
        Entity root;
    };

} // engine

#endif //BUILDANDPROGRAMM_SCENE_HPP
