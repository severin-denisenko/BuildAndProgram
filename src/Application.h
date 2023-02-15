//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_APPLICATION_H
#define BUILDANDPROGRAMM_APPLICATION_H

#include <utility>
#include <thread>

#include <Window.hpp>
#include <Entity.hpp>
#include <Text.hpp>
#include <Background.hpp>
#include <Scene.hpp>

using engine::Window;
using namespace std::chrono_literals;

class Application {
public:
    void Run(){
        Window window("Build And Program");

        engine::Scene scene;

        scene.root.AddComponent(new engine::Background(WHITE));

        scene.root.AddComponent(new engine::Text("Build And Program",
                                             GetScreenWidth()/ 2, GetScreenHeight() / 2,
                                             20, GRAY));


        while (!WindowShouldClose()){
            scene.Apply();
            scene.Render();
        }
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
