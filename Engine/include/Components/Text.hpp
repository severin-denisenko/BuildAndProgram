//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_TEXT_H
#define BUILDANDPROGRAMM_TEXT_H

#include "Entity.hpp"
#include "Component.hpp"

#include "raylib.h"

namespace engine {
    class Text : public Component {
    public:
        Text(const char* text, int font_size, Color color) : text(text),
        font_size(font_size), color(color) {}

        void Create(Entity *entity) override{
            transform = entity->GetComponent<Transform>();
        }

        void Render2D(Entity *entity) override{
            DrawText(text, (int) transform->x,
                     (int) transform->y,
                     font_size, color);
        }

        const char* text;
        int font_size;
        Color color;
        engine::Transform* transform;
    };
} // engine

#endif //BUILDANDPROGRAMM_TEXT_H
