//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_ESPRITE_HPP
#define BUILDANDPROGRAMM_ESPRITE_HPP

#include "EComponent.hpp"

#include "raylib.h"

namespace engine {
    class ESprite : public EComponent {
    public:
        explicit ESprite(const char * filename, Color color = WHITE) : filename(filename), color(color){
            image = LoadImage(filename);

            source_rectangle = { 0.0f, 0.0f, (float)image.width, (float)image.height};
            origin = { (float)0, (float)0 };

            texture = LoadTextureFromImage(image);
        }

        void Create(EEntity* entity) override{
            transform = entity->GetComponent<ETransform>();
        }

        void Render2D(EEntity *entity) override{
            destination_rectangle = { transform->x,
                                      transform->y,
                                      (float)image.width * transform->sx,
                                      (float)image.height * transform->sy};

            DrawTexturePro(texture, source_rectangle, destination_rectangle, origin,
                           (float)transform->rz, color);
        }

        ~ESprite() override{
            UnloadTexture(texture);
        }

        const char * filename;
        Image image;
        Rectangle source_rectangle;
        Rectangle destination_rectangle;
        Vector2 origin;
        Texture2D texture;
        engine::ETransform* transform;
        Color color;
    };
} // engine

#endif //BUILDANDPROGRAMM_ESPRITE_HPP
