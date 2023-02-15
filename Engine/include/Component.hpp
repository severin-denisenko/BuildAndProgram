//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_COMPONENT_HPP
#define BUILDANDPROGRAMM_COMPONENT_HPP

namespace engine {
    class Component {
    public:
        virtual void Apply() {};
        virtual void Render2D() {};
        virtual void Render3D() {};

        virtual ~Component() = default;
    };
} // engine

#endif //BUILDANDPROGRAMM_COMPONENT_HPP
