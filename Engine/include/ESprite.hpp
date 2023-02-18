//
// Created by Severin on 17.02.2023.
//

#ifndef BUILDANDPROGRAMM_ESPRITE_HPP
#define BUILDANDPROGRAMM_ESPRITE_HPP

#include "ETexture.hpp"

namespace Engine {

    class ESprite {
    public:
        explicit ESprite(const ETexture& texture) : texture(texture) {
            origin = {0, 0};
            source = {0, 0, (float)texture.Width(), (float)texture.Height()};
            rotation = 0;
            scale = {1, 1};
            destination = source;
        }

        void Render(){
            DrawTexturePro(texture.Get(), source, destination, origin,
                           rotation, color);
        }

        void Render(float x, float y){
            DrawTexturePro(texture.Get(), source,
                           {x, y, source.width * scale.x, source.height * scale.y},
                           origin, rotation, color);
        }

        Rectangle source;
        Rectangle destination;
        float rotation;
        Vector2 origin;
        Vector2 scale;
        Color color = WHITE;
    private:
        const ETexture& texture;
    };
} // Engine

#endif //BUILDANDPROGRAMM_ESPRITE_HPP
