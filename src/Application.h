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
            Engine::EEntity* new_entity = Engine::EEntityFactory("wolic", entity->GetScene())
                    .Rectangle(sprite)
                    .Transform(GetMousePosition().x, GetMousePosition().y, 0, 0, 2, 2)
                    .RigidBody().Get();

            new_entity->GetComponent<Engine::ERigidBody>()->acceleration_x = (float)GetRandomValue(-100, 100);
            new_entity->GetComponent<Engine::ERigidBody>()->acceleration_y = (float)GetRandomValue(-200, 100);

            new_entity->GetComponent<Engine::ERectangle>()->sprite.color = {(unsigned char)GetRandomValue(0, 255),
                                                                            (unsigned char)GetRandomValue(0, 255),
                                                                            (unsigned char)GetRandomValue(0, 255),
                                                                            (unsigned char)GetRandomValue(0, 255)};

            entity->AddEntity(new_entity);
            entity->GetScene().creator.Add(new_entity);
            entity->GetScene().updater.Add(new_entity);
            entity->GetScene().renderer.Add2D(new_entity);
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
        Engine::EWindow window("Build And Program", true);

        S_LOG_LEVEL_INFO;

        Engine::EScene scene;

        Engine::EEntity* first = Engine::EEntityFactory("Background", scene).Background(WHITE).Get();

        scene.root->AddEntity(first);
        scene.renderer.Add2D(first);
        scene.creator.Add(first);

        Engine::EEntity* second = Engine::EEntityFactory("Spawner", scene).Transform(10, 40)
                .Add(new MyThirdComponent())
                .Add(new MySecondComponent())
                .Get();

        scene.root->AddEntity(second);
        scene.renderer.Add2D(second);
        scene.updater.Add(second);
        scene.creator.Add(second);

        Engine::EEntity* third = Engine::EEntityFactory("FPS", scene).Transform(10, 10).FPSLabel().Get();

        scene.root->AddEntity(third);
        scene.renderer.Add2D(third);
        scene.creator.Add(third);

        Engine::EEngine engine(scene, window);
        engine.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
