//
// Created by Severin on 15.02.2023.
//

#include "EWindow.hpp"

#include "raylib.h"

namespace Engine{
    EWindow::EWindow(const char* name) {
        const int screenWidth = GetScreenWidth();
        const int screenHeight = GetScreenHeight();

        InitWindow(screenWidth, screenHeight, name);

        SetTargetFPS(60);

        ToggleFullscreen();
    }

    EWindow::~EWindow() {
        CloseWindow();
    }
}

