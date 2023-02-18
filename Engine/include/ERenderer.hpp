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
        ERenderer();

        void Add2D(Engine::EEntity* entity);
        void Add3D(Engine::EEntity* entity);

        void Render(Camera2D& camera2D, Camera3D& camera3D);

    private:
        std::vector<Engine::EEntity*> entities2D;
        std::vector<Engine::EEntity*> entities3D;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ERENDERER_HPP
