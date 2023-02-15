//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_APPLICATION_H
#define BUILDANDPROGRAMM_APPLICATION_H

#include <utility>
#include <thread>

#include <Window.hpp>
#include <Entity.hpp>
#include <Scene.hpp>
#include "Components/Text.hpp"
#include "Components/Background.hpp"
#include "Components/SimpleImage.hpp"
#include "Components/Transform.hpp"

using engine::Window;
using namespace std::chrono_literals;

class Application {
public:
    void Run(){
        Window window("Build And Program");

        engine::Scene scene;

        scene.root.AddComponent(new engine::Transform());
        scene.root.AddComponent(new engine::Background(WHITE));
        scene.root.AddComponent(new engine::Text("Build And Program",
                                             20, GRAY));
        scene.root.AddComponent(new engine::SimpleImage("src/img.png"));

        while (!WindowShouldClose()){
            scene.Apply();
            scene.Render();
        }
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
