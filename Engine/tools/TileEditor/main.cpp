//
// Created by Severin on 22.02.2023.
//

#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>

int main(){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(900, 600, "raygui - controls test suite");

    while (!WindowShouldClose()){
        BeginDrawing();

        GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        GuiDrawRectangle({0., 0., (float)GetRenderWidth() / 2, (float)GetRenderHeight()}, 1, BLACK, WHITE);

        

        EndDrawing();
    }
}
