//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_APPLICATION_H
#define BUILDANDPROGRAMM_APPLICATION_H

#include <Window.hpp>
#include <Scene.hpp>

#include <EntityFactory.h>

class MyComponent : public engine::Component{
    void Apply(engine::Entity * entity) override{
        if(!transform)
            transform = entity->GetComponent<engine::Transform>();

        transform->x++;
        transform->y++;
        transform->rz++;
    }

    engine::Transform* transform = nullptr;
};

class Application {
public:
    void Run(){
        engine::Window window("Build And Program");

        engine::Scene scene;

        scene.root.AddEntity(engine::EntityFactory("Background").Background(WHITE).Get());
        scene.root.AddEntity(engine::EntityFactory("Demo text").Transform(10, 10).Text("wabit demo.", 40, BLACK).Get());
        scene.root.AddEntity(engine::EntityFactory("wolic").Transform(0, 0, 0, 0, 10, 10).Sprite("src/img.png", RED).Add(new MyComponent()).Get());

        scene.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
