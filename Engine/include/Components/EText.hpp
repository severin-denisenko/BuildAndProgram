//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_TEXT_H
#define BUILDANDPROGRAMM_TEXT_H

#include "EEntity.hpp"
#include "EComponent.hpp"

#include "raylib.h"

namespace Engine {
    class EText : public EComponent {
    public:
        EText(const char* text, int font_size, Color color) : text(text),
                                                              font_size(font_size), color(color) {}

        void Create(EEntity *entity) override{
            transform = entity->GetComponent<ETransform>();
        }

        void Render2D(EEntity *entity) override{
            DrawText(text, (int) transform->x,
                     (int) transform->y,
                     font_size, color);
        }

        const char* text;
        int font_size;
        Color color;
        Engine::ETransform* transform;
    };
} // engine

#endif //BUILDANDPROGRAMM_TEXT_H
