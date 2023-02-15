//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_SIMPLEIMAGE_HPP
#define BUILDANDPROGRAMM_SIMPLEIMAGE_HPP

#include "Component.hpp"

#include "raylib.h"

namespace engine {
    class SimpleImage : public Component {
    public:
        explicit SimpleImage(const char * filename) : filename(filename){
            image = LoadImage(filename);
            texture = LoadTextureFromImage(image);
        }

        void Render2D(Entity *entity) override{
            DrawTexture(texture, (int) entity->GetComponent<Transform>()->x,
                        (int) entity->GetComponent<Transform>()->y, WHITE);
        }

        const char * filename;
        Image image;
        Texture2D texture;
    };
} // engine

#endif //BUILDANDPROGRAMM_SIMPLEIMAGE_HPP
