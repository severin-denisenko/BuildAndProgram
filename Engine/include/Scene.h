//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_SCENE_H
#define BUILDANDPROGRAMM_SCENE_H

#include "Entity.hpp"

#include "raylib.h"

namespace engine {

    class Scene {
    public:
        Scene() = default;

        void Apply(){
            root.Apply();
        }

        void Render2D();;

        void Render3D();

        void Render();

        Camera camera = { { 5.0f, 5.0f, 5.0f },
                          { 0.0f, 0.0f, 0.0f },
                          { 0.0f, 1.0f, 0.0f },
                          45.0f, 0 };;
        Entity root;
    };

} // engine

#endif //BUILDANDPROGRAMM_SCENE_H
