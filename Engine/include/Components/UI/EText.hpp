//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_TEXT_H
#define BUILDANDPROGRAMM_TEXT_H

#include <string>
#include <utility>

#include "EEntity.hpp"
#include "Components/EComponent.hpp"

#include "raylib.h"

namespace Engine {
    class EText : public EComponent {
    public:
        EText(std::string text, int font_size, Color color) : text(std::move(text)),
                                                              font_size(font_size), color(color) {}

        void Create(EEntity *entity) override{
            transform = entity->GetComponent<ETransform>();
            S_INFO("Component EText created.");
        }

        void RenderUI(EEntity *entity) override{
            if (transform == nullptr)
                S_FATAL("ETransform is null!");

            DrawText(text.c_str(), (int) transform->x,
                     (int) transform->y,
                     font_size, color);
        }

        std::string text;
        int font_size;
        Color color;
        Engine::ETransform* transform;
    };
} // engine

#endif //BUILDANDPROGRAMM_TEXT_H
