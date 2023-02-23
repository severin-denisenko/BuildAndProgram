//
// Created by Severin on 15.02.2023.
//

#include "EWindow.hpp"

#include "raylib.h"

namespace Engine{
    EWindow::EWindow(const char* name, bool fullScreen) {
        const int screenWidth = GetScreenWidth();
        const int screenHeight = GetScreenHeight();

        SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);

        if (fullScreen){
            InitWindow(screenWidth, screenHeight, name);
            ToggleFullscreen();
        } else{
            InitWindow(600, 600, name);
        }

        SetTargetFPS(60);
    }

    bool EWindow::Open() {
        return !WindowShouldClose();
    }

    EWindow::~EWindow() {
        CloseWindow();
    }
}

