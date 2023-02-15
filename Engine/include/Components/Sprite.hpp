//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_SPRITE_HPP
#define BUILDANDPROGRAMM_SPRITE_HPP

#include "Component.hpp"

#include "raylib.h"

namespace engine {
    class Sprite : public Component {
    public:
        explicit Sprite(const char * filename) : filename(filename){
            image = LoadImage(filename);

            source_rectangle = { 0.0f, 0.0f, (float)image.width, (float)image.height};
            origin = { (float)0, (float)0 };

            texture = LoadTextureFromImage(image);
        }

        void Render2D(Entity *entity) override{
            transform = entity->GetComponent<Transform>();

            destination_rectangle = { transform->x,
                                      transform->y,
                                      transform->x + (float)image.width * transform->sx,
                                      transform->y + (float)image.height * transform->sy};

            DrawTexturePro(texture, source_rectangle, destination_rectangle, origin,
                           (float)transform->rz, WHITE);
        }

        const char * filename;
        Image image;
        Rectangle source_rectangle;
        Rectangle destination_rectangle;
        Vector2 origin;
        Texture2D texture;
        engine::Transform* transform;
    };
} // engine

#endif //BUILDANDPROGRAMM_SPRITE_HPP
