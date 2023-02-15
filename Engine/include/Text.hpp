//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_TEXT_H
#define BUILDANDPROGRAMM_TEXT_H

#include "Component.hpp"

#include "raylib.h"

namespace engine {
    class Text : public Component {
    public:
        Text(const char* text, int x_position, int y_position, int font_size, Color color) : text(text) ,
        x_position(x_position), y_position(y_position), font_size(font_size), color(color) {}

        void Render2D() override{
            DrawText(text, x_position, y_position,
                     font_size, color);
        }

        const char* text;
        int x_position;
        int y_position;
        int font_size;
        Color color;
    };
} // engine

#endif //BUILDANDPROGRAMM_TEXT_H
