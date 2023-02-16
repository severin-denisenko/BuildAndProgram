//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_APPLICATION_H
#define BUILDANDPROGRAMM_APPLICATION_H

#include <Window.hpp>
#include <Scene.hpp>

#include <EntityFactory.h>

class MyComponent : public engine::Component{
public:
    MyComponent(){
        speed_x = GetRandomValue(-100, 100);
        speed_y = GetRandomValue(-100, 100);
    }

    void Create(engine::Entity* entity) override{
        transform = entity->GetComponent<engine::Transform>();
        sprite = entity->GetComponent<engine::Sprite>();
    }

    void Update(engine::Entity* entity) override{
        transform->x += speed_x * GetFrameTime();
        transform->y += speed_y * GetFrameTime();

        if (transform->x > GetScreenWidth() - sprite->source_rectangle.width * 2 || transform->x < 0)
            speed_x *= -1;
        if (transform->y > GetScreenHeight() - sprite->source_rectangle.height * 2 || transform->y < 0)
            speed_y *= -1;
    }

    float speed_x;
    float speed_y;

    engine::Transform* transform;
    engine::Sprite* sprite;
};

class MySecondComponent : public engine::Component{
    void Update(engine::Entity* entity) override{
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            entity->AddEntity(engine::EntityFactory("wolic")
                                      .Transform(GetMousePosition().x, GetMousePosition().y, 0, 0, 2, 2)
                                      .Sprite("src/img.png", WHITE)
                                      .Add(new MyComponent()).Get());
        }
    }
};

class Application {
public:
    void Run(){
        engine::Window window("Build And Program");

        engine::Scene scene;

        scene.root.AddEntity(engine::EntityFactory("Background").Background(WHITE).Get());

        scene.root.AddEntity(engine::EntityFactory("Spawner")
                                  .Add(new MySecondComponent()).Get());

        scene.root.AddEntity(engine::EntityFactory("FPS").Transform(10, 10).FPSLabel().Get());

        scene.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
