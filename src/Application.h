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

        scene.root.AddEntity(engine::EntityFactory("Background").Background(WHITE).Get());
        scene.root.AddEntity(engine::EntityFactory("Demo text").Transform(10, 10).Text("wabit demo.", 40, BLACK).Get());

        scene.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
