//
// Created by Severin on 24.02.2023.
//

#ifndef BUILDANDPROGRAMM_EBUTTON_HPP
#define BUILDANDPROGRAMM_EBUTTON_HPP

#include "Components/EComponent.hpp"
#include "Components/ETransform.hpp"
#include "Graphics/ETileSet.hpp"

namespace Engine {

    class EButton : public EComponent{
    public:
        enum ButtonAction{
            NONE,
            FOCUSED,
            PRESSED,
            HOLD,
            RELEASED,
        };

        EButton(ETileSet tileSet) : tileSet(tileSet) {}

        void Create(EEntity* entity) override{
            transform = entity->GetComponent<ETransform>();
        }

        void Update(EEntity* entity) override{
            Vector2 mousePosition = GetMousePosition();

            action = NONE;

            if (CheckCollisionPointRec(mousePosition,
                                       (Rectangle){transform->GetGlobalPosition().x, transform->GetGlobalPosition().y,
                                                   transform->GetGlobalScale().x * tileSet.width,
                                                   transform->GetGlobalScale().y * tileSet.height})){

                if (IsMouseButtonUp(MOUSE_BUTTON_LEFT)) action = FOCUSED;
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) action = PRESSED;
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) action = HOLD;
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) action = RELEASED;
            }
        }

        void RenderUI(EEntity* entity) override{

            size_t renderIndex;

            switch (action) {
                case NONE:
                    renderIndex = noneIndex;
                    break;
                case FOCUSED:
                    renderIndex = focusedIndex;
                    break;
                case PRESSED:
                    renderIndex = pressedIndex;
                    break;
                case HOLD:
                    renderIndex = pressedIndex;
                    break;
                case RELEASED:
                    renderIndex = focusedIndex;
                    break;
            }

            tileSet.Render(transform->GetGlobalPosition().x, transform->GetGlobalPosition().y,
                           transform->GetGlobalScale().x, transform->GetGlobalScale().y,
                           renderIndex);
        }

        ButtonAction action;
        size_t noneIndex = 0;
        size_t focusedIndex = 1;
        size_t pressedIndex = 2;
    private:

        ETileSet tileSet;
        ETransform* transform = nullptr;
    };

} // Engine

#endif //BUILDANDPROGRAMM_EBUTTON_HPP
