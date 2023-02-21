//
// Created by Severin on 17.02.2023.
//

#ifndef BUILDANDPROGRAMM_ESPRITE_HPP
#define BUILDANDPROGRAMM_ESPRITE_HPP

#include <raylib.h>

namespace Engine {

    class ESprite {
    public:
        explicit ESprite(const Texture& texture) : texture(texture) {
            origin = {(float)texture.width/2, (float)texture.height/2};
            source = {0, 0, (float)texture.width, (float)texture.height/2};
            rotation = 0;
            scale = {1, 1};
            destination = source;
        }

        void Render(){
            DrawTexturePro(texture, source, destination, origin,
                           rotation, color);
        }

        void Render(float x, float y, float scale_x, float scale_y){
            DrawTexturePro(texture, source,
                           {x, y, source.width * scale.x * scale_x, source.height * scale.y * scale_x},
                           origin, rotation, color);
        }

        Rectangle source;
        Rectangle destination;
        float rotation;
        Vector2 origin;
        Vector2 scale;
        Color color = WHITE;
    private:
        const Texture texture;
    };
} // Engine

#endif //BUILDANDPROGRAMM_ESPRITE_HPP
