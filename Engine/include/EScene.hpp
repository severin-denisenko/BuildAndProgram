//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_ESCENE_HPP
#define BUILDANDPROGRAMM_ESCENE_HPP

#include "EEntity.hpp"

#include <raylib.h>

namespace Engine {

    class EScene {
    public:
        EScene() = default;

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
        EEntity root;
    };

} // engine

#endif //BUILDANDPROGRAMM_ESCENE_HPP
