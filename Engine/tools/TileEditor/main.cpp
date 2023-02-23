//
// Created by Severin on 22.02.2023.
//

#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>

int main(){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(900, 600, "raygui - controls test suite");

    bool loadImageButtonPressed = false;
    bool loadFileButtonPressed = false;
    bool saveFileButtonPressed = false;
    bool sectionsXEditMode = false;
    bool sectionsYEditMode = false;

    float elementHeight = 30;

    int sectionsX = 10;
    int sectionsY = 10;
    int maxSections = 100;
    int minSections = 1;

    while (!WindowShouldClose()){
        auto leftPanelWidth = (float)GetRenderWidth() / 5 * 2;
        auto leftPanelHeight = (float)GetRenderHeight();

        BeginDrawing();

        GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        GuiDrawRectangle({0., 0., leftPanelWidth, leftPanelHeight}, 1, BLACK, WHITE);

        loadImageButtonPressed = GuiButton((Rectangle){ 0, 0, leftPanelWidth / 3, elementHeight },
                                      "Load image");

        loadFileButtonPressed = GuiButton((Rectangle){ leftPanelWidth / 3, 0, leftPanelWidth / 3, elementHeight },
                                           "Load file");

        saveFileButtonPressed = GuiButton((Rectangle){ leftPanelWidth / 3 * 2, 0, leftPanelWidth / 3, elementHeight },
                                          "Save file");

        if(GuiValueBox((Rectangle){ 0, elementHeight, leftPanelWidth / 2, elementHeight}, NULL,
                       &sectionsX, minSections, maxSections, sectionsXEditMode)) sectionsXEditMode = !sectionsXEditMode;

        if(GuiValueBox((Rectangle){ leftPanelWidth / 2, elementHeight, leftPanelWidth / 2, elementHeight}, NULL,
                    &sectionsY, minSections, maxSections, sectionsYEditMode)) sectionsYEditMode = !sectionsYEditMode;


        EndDrawing();
    }
}
