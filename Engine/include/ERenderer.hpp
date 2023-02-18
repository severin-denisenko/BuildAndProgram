//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_ERENDERER_HPP
#define BUILDANDPROGRAMM_ERENDERER_HPP

#include <vector>
#include <raylib.h>

namespace Engine {
    class EEntity;

    class ERenderer {
    public:
        ERenderer() = default;

        void Add2D(Engine::EEntity* entity);
        void Add3D(Engine::EEntity* entity);

        void Render();

    private:
        Camera camera = { { 5.0f, 5.0f, 5.0f },
                          { 0.0f, 0.0f, 0.0f },
                          { 0.0f, 1.0f, 0.0f },
                          45.0f, 0 };;

        std::vector<Engine::EEntity*> entities2D;
        std::vector<Engine::EEntity*> entities3D;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ERENDERER_HPP
