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
        Text(const char* text, int position_x, int position_y, int font_size, Color color) : text(text),
        position_x(position_x), position_y(position_y), font_size(font_size), color(color) {}

        void Render2D(Entity *entity) override{
            DrawText(text, position_x, position_y,
                     font_size, color);
        }

        const char* text;
        int position_x;
        int position_y;
        int font_size;
        Color color;
    };
} // engine

#endif //BUILDANDPROGRAMM_TEXT_H
