//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_APPLICATION_H
#define BUILDANDPROGRAMM_APPLICATION_H

#include <EWindow.hpp>
#include <EScene.hpp>
#include <ESprite.hpp>

#include <EEntityFactory.h>

class MySecondComponent : public Engine::EComponent{
    void Update(Engine::EEntity* entity) override{
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            for (int i = 0; i < 1; ++i) {
                entity->AddEntity(Engine::EEntityFactory("wolic")
                                          .Rectangle(sprite)
                                          .Transform(GetMousePosition().x, GetMousePosition().y, 0, 0, 2, 2)
                                          .RigidBody().Get());

            }
        }
    }

    Engine::ETexture texture = Engine::ETexture("src/img.png");
    Engine::ESprite sprite = Engine::ESprite(texture);
};

class MyThirdComponent : public Engine::EText{
public:
    MyThirdComponent() : Engine::EText("Wabits count: 0", 22, BLACK) {}

    void Update(Engine::EEntity* entity) override{
        Engine::EText::Update(entity);

        text = "Wabits count: " + std::to_string(entity->GetChildCount());
    }
};

class Application {
public:
    void Run(){
        Engine::EWindow window("Build And Program");

        S_LOG_LEVEL_INFO;

        Engine::EScene scene;

        scene.root.AddEntity(Engine::EEntityFactory("Background").Background(WHITE).Get());

        scene.root.AddEntity(Engine::EEntityFactory("Spawner").Transform(10, 40)
                                     .Add(new MyThirdComponent())
                                     .Add(new MySecondComponent())
                                     .Get());

        scene.root.AddEntity(Engine::EEntityFactory("FPS").Transform(10, 10).FPSLabel().Get());

        scene.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
