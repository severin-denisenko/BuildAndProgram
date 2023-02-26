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

#include <Graphics/ETileMap.hpp>
#include <SLib/SLog.hpp>

int main(){
    S_LOG_LEVEL_INFO;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(900, 600, "raygui - controls test suite");

    bool loadImageButtonPressed = false;
    bool loadFileButtonPressed = false;
    bool saveFileButtonPressed = false;
    bool sectionsXEditMode = false;
    bool sectionsYEditMode = false;

    float elementHeight = 30;

    std::string loadedImageFilename;
    std::string loadedFileFilename;

    int sectionsX = 10;
    int sectionsY = 10;
    int maxSections = 100;
    int minSections = 1;

    int tileMapHeight = 8;
    int tileMapWith = 8;
    int maxTileMapHeight = 100;
    int minTileMapHeight = 1;

    bool tileMapHeightEditMode = false;
    bool tileMapWithEditMode = false;

    int currentTileSelected = 0;

    Texture tileSetTexture = { 0 };

    GuiFileDialogState loadImageFileDialogState = InitGuiFileDialog(GetWorkingDirectory());
    GuiFileDialogState loadFileFileDialogState = InitGuiFileDialog(GetWorkingDirectory());
    GuiFileDialogState saveFileFileDialogState = InitGuiFileDialog(GetWorkingDirectory());

    Engine::ETileSet set(tileSetTexture);
    Engine::ETileMap map(set);

    Rectangle textureRectangle;
    Rectangle tileSetRectangle;

    while (!WindowShouldClose()){
        Vector2 mousePosition = GetMousePosition();

        for (int i = 0; i < sectionsX; ++i) {
            for (int j = 0; j < sectionsY; ++j) {
                if (CheckCollisionPointRec(mousePosition, {textureRectangle.x + textureRectangle.width / sectionsX * i,
                                                           textureRectangle.y + textureRectangle.height / sectionsY * j,
                                                           textureRectangle.width / sectionsX, textureRectangle.height / sectionsY}))
                {
                    if (GetGestureDetected() == GESTURE_TAP){
                        currentTileSelected = i * sectionsY + j;

                        S_INFO("Selected tile: " + std::to_string(currentTileSelected));
                    }
                }
            }
        }

        for (int i = 0; i < map.width; ++i) {
            for (int j = 0; j < map.height; ++j) {
                if (CheckCollisionPointRec(mousePosition, {tileSetRectangle.x + tileSetRectangle.width / map.width * i,
                                                           tileSetRectangle.y + tileSetRectangle.height / map.height * j,
                                                           tileSetRectangle.width / map.width, tileSetRectangle.height / map.height}))
                {
                    if (GetGestureDetected() == GESTURE_TAP){
                        map(i, j) = currentTileSelected;

                        S_INFO("Changed tile: " + std::to_string(currentTileSelected));
                    }
                }
            }
        }

        auto leftPanelWidth = (float)GetRenderWidth() / 5 * 2;
        auto leftPanelHeight = (float)GetRenderHeight();

        if (loadFileFileDialogState.SelectFilePressed)
        {
            if (IsFileExtension(loadFileFileDialogState.fileNameText, ".tiles"))
            {
                loadedFileFilename = TextFormat("%s/%s", loadFileFileDialogState.dirPathText, loadFileFileDialogState.fileNameText);

                set = Engine::ETileSet(tileSetTexture);
                set.Splice(sectionsX, sectionsY);
                set.SetOrigin({0, 0});

                map = Engine::ETileMap(set);
                map.Load(loadedFileFilename);

                tileMapHeight = map.height;
                tileMapWith = map.width;
            }

            loadFileFileDialogState.SelectFilePressed = false;
        }

        if (saveFileFileDialogState.SelectFilePressed)
        {
            if (IsFileExtension(saveFileFileDialogState.fileNameText, ".tiles"))
            {
                std::string filename(TextFormat("%s/%s", saveFileFileDialogState.dirPathText, saveFileFileDialogState.fileNameText));
                map.Save(filename);
            }

            saveFileFileDialogState.SelectFilePressed = false;
        }

        if (loadImageFileDialogState.SelectFilePressed)
        {
            if (IsFileExtension(loadImageFileDialogState.fileNameText, ".png"))
            {
                loadedImageFilename = TextFormat("%s/%s", loadImageFileDialogState.dirPathText, loadImageFileDialogState.fileNameText);
                UnloadTexture(tileSetTexture);
                tileSetTexture = LoadTexture(loadedImageFilename.c_str());

                set = Engine::ETileSet(tileSetTexture);
                set.Splice(sectionsX, sectionsY);
                set.SetOrigin({0, 0});

                map = Engine::ETileMap(set);

                textureRectangle = {0, elementHeight * 3, leftPanelWidth, leftPanelWidth * tileSetTexture.width / tileSetTexture.height};
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

        if(GuiValueBox((Rectangle){ 1, elementHeight, leftPanelWidth / 2 - 1, elementHeight}, nullptr,
                       &sectionsX, minSections, maxSections, sectionsXEditMode)) sectionsXEditMode = !sectionsXEditMode;

        if(GuiValueBox((Rectangle){ leftPanelWidth / 2, elementHeight, leftPanelWidth / 2 - 1, elementHeight}, nullptr,
                    &sectionsY, minSections, maxSections, sectionsYEditMode)) sectionsYEditMode = !sectionsYEditMode;

        if(GuiValueBox((Rectangle){ 1, elementHeight * 2, leftPanelWidth / 2 - 1, elementHeight}, nullptr,
                       &tileMapHeight, minTileMapHeight, maxTileMapHeight, tileMapHeightEditMode)) tileMapHeightEditMode = !tileMapHeightEditMode;

        if(GuiValueBox((Rectangle){ leftPanelWidth / 2, elementHeight * 2, leftPanelWidth / 2 - 1, elementHeight}, nullptr,
                       &tileMapWith, minTileMapHeight, maxTileMapHeight, tileMapWithEditMode)) tileMapWithEditMode = !tileMapWithEditMode;

        if (tileSetTexture.id != 0){
            map.Resize(tileMapHeight, tileMapWith);

            DrawTexturePro(tileSetTexture, (Rectangle){0, 0, tileSetTexture.width, tileSetTexture.height},
                           textureRectangle,(Vector2){0, 0},0, WHITE);

            tileSetRectangle = {leftPanelWidth, 0, map.width * 3 * tileSetTexture.width / sectionsX,
                                map.height * 3 * tileSetTexture.height / sectionsY};

            map.Render(leftPanelWidth, 0, 3, 3);
        }

        if (loadImageButtonPressed) loadImageFileDialogState.windowActive = true;
        GuiUnlock();
        GuiFileDialog(&loadImageFileDialogState);

        if (loadFileButtonPressed) loadFileFileDialogState.windowActive = true;
        GuiUnlock();
        GuiFileDialog(&loadFileFileDialogState);

        if (saveFileButtonPressed) saveFileFileDialogState.windowActive = true;
        GuiUnlock();
        GuiFileDialog(&saveFileFileDialogState);

        EndDrawing();
    }
}
