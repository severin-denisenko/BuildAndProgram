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

        void Add2D(EEntity* entity);
        void Add3D(EEntity* entity);
        void AddUI(EEntity* entity);

        void Render(Camera2D& camera2D, Camera3D& camera3D);

        void Remove2D(EEntity *entity);
        void RemoveUI(EEntity *entity);

        void Remove3D(EEntity *pEntity);

    private:
        std::vector<EEntity*> entities2D;
        std::vector<EEntity*> entities3D;
        std::vector<EEntity*> entitiesUI;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ERENDERER_HPP
