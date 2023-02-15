//
// Created by Severin on 15.02.2023.
//

#include "Window.hpp"

#include "raylib.h"

namespace engine{
    Window::Window(const char* name) {
        const int screenWidth = GetScreenWidth();
        const int screenHeight = GetScreenHeight();

        InitWindow(screenWidth, screenHeight, name);

        SetTargetFPS(60);

        ToggleFullscreen();
    }

    Window::~Window() {
        CloseWindow();
    }
}

