//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_APPLICATION_H
#define BUILDANDPROGRAMM_APPLICATION_H

#include <EWindow.hpp>
#include <EScene.hpp>
#include <ESprite.hpp>
#include <EEngine.hpp>
#include <EEntityFactory.hpp>

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

        Engine::EEntity* first = Engine::EEntityFactory("Background").Background(WHITE).Get();

        scene.root.AddEntity(first);
        scene.renderer.Add2D(first);
        scene.creator.Add(first);

        Engine::EEntity* second = Engine::EEntityFactory("Spawner").Transform(10, 40)
                .Add(new MyThirdComponent())
                .Add(new MySecondComponent())
                .Get();

        scene.root.AddEntity(second);
        scene.renderer.Add2D(second);
        scene.updater.Add(second);
        scene.creator.Add(second);

        Engine::EEntity* third = Engine::EEntityFactory("FPS").Transform(10, 10).FPSLabel().Get();

        scene.root.AddEntity(third);
        scene.renderer.Add2D(third);
        scene.creator.Add(third);

        Engine::EEngine engine(scene, window);
        engine.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
