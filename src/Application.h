//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_APPLICATION_H
#define BUILDANDPROGRAMM_APPLICATION_H

#include <EWindow.hpp>
#include <EScene.hpp>

#include <EEntityFactory.h>

class MyComponent : public Engine::EComponent{
public:
    MyComponent(){
        speed_x = GetRandomValue(-100, 100);
        speed_y = GetRandomValue(-100, 100);
    }

    void Create(Engine::EEntity* entity) override{
        transform = entity->GetComponent<Engine::ETransform>();
        sprite = entity->GetComponent<Engine::ESprite>();
    }

    void Update(Engine::EEntity* entity) override{
        transform->x += speed_x * GetFrameTime();
        transform->y += speed_y * GetFrameTime();

        if (transform->x > GetScreenWidth() - sprite->source_rectangle.width * 2 || transform->x < 0)
            speed_x *= -1;
        if (transform->y > GetScreenHeight() - sprite->source_rectangle.height * 2 || transform->y < 0)
            speed_y *= -1;
    }

    float speed_x;
    float speed_y;

    Engine::ETransform* transform;
    Engine::ESprite* sprite;
};

class MySecondComponent : public Engine::EComponent{
    void Update(Engine::EEntity* entity) override{
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            entity->AddEntity(Engine::EEntityFactory("wolic")
                                      .Transform(GetMousePosition().x, GetMousePosition().y, 0, 0, 2, 2)
                                      .Sprite("src/img.png", WHITE)
                                      .Add(new MyComponent()).Get());
        }
    }
};

class Application {
public:
    void Run(){
        Engine::EWindow window("Build And Program");

        Engine::EScene scene;

        scene.root.AddEntity(Engine::EEntityFactory("Background").Background(WHITE).Get());

        scene.root.AddEntity(Engine::EEntityFactory("Spawner")
                                  .Add(new MySecondComponent()).Get());

        scene.root.AddEntity(Engine::EEntityFactory("FPS").Transform(10, 10).FPSLabel().Get());

        scene.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
