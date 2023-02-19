//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_ECOMPONENT_HPP
#define BUILDANDPROGRAMM_ECOMPONENT_HPP

namespace Engine {
    class EEntity;

    class EComponent {
    public:
        virtual void Update(EEntity* entity) {};
        virtual void Create(EEntity* entity) {};
        virtual void Render2D(EEntity* entity) {};
        virtual void Render3D(EEntity* entity) {};
        virtual void RenderUI(EEntity* entity) {};

        virtual ~EComponent() = default;
    };
} // engine

#endif //BUILDANDPROGRAMM_ECOMPONENT_HPP
