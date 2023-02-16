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
        explicit Sprite(const char * filename, Color color = WHITE) : filename(filename), color(color){
            image = LoadImage(filename);

            source_rectangle = { 0.0f, 0.0f, (float)image.width, (float)image.height};
            origin = { (float)0, (float)0 };

            texture = LoadTextureFromImage(image);
        }

        void Render2D(Entity *entity) override{
            transform = entity->GetComponent<Transform>();

            destination_rectangle = { transform->x,
                                      transform->y,
                                      (float)image.width * transform->sx,
                                      (float)image.height * transform->sy};

            DrawTexturePro(texture, source_rectangle, destination_rectangle, origin,
                           (float)transform->rz, color);
        }

        ~Sprite() override{
            UnloadTexture(texture);
        }

        const char * filename;
        Image image;
        Rectangle source_rectangle;
        Rectangle destination_rectangle;
        Vector2 origin;
        Texture2D texture;
        engine::Transform* transform;
        Color color;
    };
} // engine

#endif //BUILDANDPROGRAMM_SPRITE_HPP
