//
// Created by Severin on 17.02.2023.
//

#ifndef BUILDANDPROGRAMM_ESPRITE_HPP
#define BUILDANDPROGRAMM_ESPRITE_HPP

#include "ETexture.hpp"

namespace Engine {

    class ESprite {
    public:
        explicit ESprite(const ETexture& texture);

        void Render();

        Rectangle source;
        Rectangle destination;
        float rotation;
        Vector2 origin;
        Color color = WHITE;

    private:
        const ETexture& texture;
    };
} // Engine

#endif //BUILDANDPROGRAMM_ESPRITE_HPP
