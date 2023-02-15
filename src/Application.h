//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_APPLICATION_H
#define BUILDANDPROGRAMM_APPLICATION_H

#include <Window.hpp>
#include <Scene.hpp>

#include <EntityFactory.h>

class Application {
public:
    void Run(){
        engine::Window window("Build And Program");

        engine::Scene scene;

        auto* transform = new engine::Transform();
        transform->rz = 30;

        scene.root.AddEntity(engine::EntityFactory().Transform()
        .Background(WHITE).Sprite("src/img.png").Get());

        while (!WindowShouldClose()){
            scene.Apply();
            scene.Render();
        }
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
