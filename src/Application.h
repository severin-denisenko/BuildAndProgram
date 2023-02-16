//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_APPLICATION_H
#define BUILDANDPROGRAMM_APPLICATION_H

#include <EWindow.hpp>
#include <EScene.hpp>

#include <EEntityFactory.h>

class MyComponent : public engine::EComponent{
public:
    MyComponent(){
        speed_x = GetRandomValue(-100, 100);
        speed_y = GetRandomValue(-100, 100);
    }

    void Create(engine::EEntity* entity) override{
        transform = entity->GetComponent<engine::ETransform>();
        sprite = entity->GetComponent<engine::ESprite>();
    }

    void Update(engine::EEntity* entity) override{
        transform->x += speed_x * GetFrameTime();
        transform->y += speed_y * GetFrameTime();

        if (transform->x > GetScreenWidth() - sprite->source_rectangle.width * 2 || transform->x < 0)
            speed_x *= -1;
        if (transform->y > GetScreenHeight() - sprite->source_rectangle.height * 2 || transform->y < 0)
            speed_y *= -1;
    }

    float speed_x;
    float speed_y;

    engine::ETransform* transform;
    engine::ESprite* sprite;
};

class MySecondComponent : public engine::EComponent{
    void Update(engine::EEntity* entity) override{
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            entity->AddEntity(engine::EEntityFactory("wolic")
                                      .Transform(GetMousePosition().x, GetMousePosition().y, 0, 0, 2, 2)
                                      .Sprite("src/img.png", WHITE)
                                      .Add(new MyComponent()).Get());
        }
    }
};

class Application {
public:
    void Run(){
        engine::EWindow window("Build And Program");

        engine::EScene scene;

        scene.root.AddEntity(engine::EEntityFactory("Background").Background(WHITE).Get());

        scene.root.AddEntity(engine::EEntityFactory("Spawner")
                                  .Add(new MySecondComponent()).Get());

        scene.root.AddEntity(engine::EEntityFactory("FPS").Transform(10, 10).FPSLabel().Get());

        scene.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
