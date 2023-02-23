//
// Created by Severin on 22.02.2023.
//

#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>

#undef RAYGUI_IMPLEMENTATION
#define GUI_FILE_DIALOG_IMPLEMENTATION
#include "../examples/custom_file_dialog/gui_file_dialog.h"

#include <string>

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

    Texture tileSetTexture = { 0 };

    GuiFileDialogState loadImageFileDialogState = InitGuiFileDialog(GetWorkingDirectory());
    GuiFileDialogState loadFileFileDialogState = InitGuiFileDialog(GetWorkingDirectory());
    GuiFileDialogState saveFileFileDialogState = InitGuiFileDialog(GetWorkingDirectory());

    while (!WindowShouldClose()){
        auto leftPanelWidth = (float)GetRenderWidth() / 5 * 2;
        auto leftPanelHeight = (float)GetRenderHeight();

        if (loadImageFileDialogState.SelectFilePressed)
        {
            if (IsFileExtension(loadImageFileDialogState.fileNameText, ".png"))
            {
                std::string filename(TextFormat("%s/%s", loadImageFileDialogState.dirPathText, loadImageFileDialogState.fileNameText));
                UnloadTexture(tileSetTexture);
                tileSetTexture = LoadTexture(filename.c_str());
            }

            loadImageFileDialogState.SelectFilePressed = false;
        }

        BeginDrawing();

        GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
        ClearBackground(GRAY);
        GuiDrawRectangle({0., 0., leftPanelWidth, leftPanelHeight}, 1, BLACK, GRAY);

        loadImageButtonPressed = GuiButton((Rectangle){ 1, 0, leftPanelWidth / 3, elementHeight },
                                      "Load image");

        loadFileButtonPressed = GuiButton((Rectangle){ leftPanelWidth / 3, 0, leftPanelWidth / 3, elementHeight },
                                           "Load file");

        saveFileButtonPressed = GuiButton((Rectangle){ leftPanelWidth / 3 * 2, 0, leftPanelWidth / 3 - 1, elementHeight },
                                          "Save file");

        if(GuiValueBox((Rectangle){ 1, elementHeight, leftPanelWidth / 2 - 1, elementHeight}, NULL,
                       &sectionsX, minSections, maxSections, sectionsXEditMode)) sectionsXEditMode = !sectionsXEditMode;

        if(GuiValueBox((Rectangle){ leftPanelWidth / 2, elementHeight, leftPanelWidth / 2 - 1, elementHeight}, NULL,
                    &sectionsY, minSections, maxSections, sectionsYEditMode)) sectionsYEditMode = !sectionsYEditMode;

        if (loadImageButtonPressed) loadImageFileDialogState.windowActive = true;
        GuiUnlock();
        GuiFileDialog(&loadImageFileDialogState);

        if (loadFileButtonPressed) loadFileFileDialogState.windowActive = true;
        GuiUnlock();
        GuiFileDialog(&loadFileFileDialogState);

        if (saveFileButtonPressed) saveFileFileDialogState.windowActive = true;
        GuiUnlock();
        GuiFileDialog(&saveFileFileDialogState);

        if (tileSetTexture.id != 0){
            DrawTexturePro(tileSetTexture, (Rectangle){0, 0, tileSetTexture.width, tileSetTexture.height},
                           (Rectangle){0, elementHeight * 2, leftPanelWidth, leftPanelWidth * tileSetTexture.width / tileSetTexture.height},
                           (Vector2){0, 0},0, WHITE);
        }

        EndDrawing();
    }
}
