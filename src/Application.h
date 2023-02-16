//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_APPLICATION_H
#define BUILDANDPROGRAMM_APPLICATION_H

#include <EWindow.hpp>
#include <EScene.hpp>

#include <EEntityFactory.h>

class MyComponent : public Engine::ERectangle{
public:
    explicit MyComponent(Engine::ESprite sprite) : ERectangle(sprite) {
        speed_x = GetRandomValue(-100, 100);
        speed_y = GetRandomValue(-100, 100);
    }

    void Create(Engine::EEntity* entity) override{
        Engine::ERectangle::Create(entity);
    }

    void Update(Engine::EEntity* entity) override{
        Engine::ERectangle::Update(entity);

        transform->x += speed_x * GetFrameTime();
        transform->y += speed_y * GetFrameTime();

        if (transform->x > GetScreenWidth() - sprite.source.width * 2|| transform->x < 0)
            speed_x *= -1;
        if (transform->y > GetScreenHeight() - sprite.source.height * 2 || transform->y < 0)
            speed_y *= -1;
    }

    float speed_x;
    float speed_y;
};

class MySecondComponent : public Engine::EComponent{
    void Update(Engine::EEntity* entity) override{
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            entity->AddEntity(Engine::EEntityFactory("wolic")
                                      .Transform(GetMousePosition().x, GetMousePosition().y, 0, 0, 2, 2)
                                      .Add(new MyComponent(sprite)).Get());
        }
    }

    Engine::ETexture texture = Engine::ETexture("src/img.png");
    Engine::ESprite sprite = Engine::ESprite(texture);
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
