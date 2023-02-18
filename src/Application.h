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
#include <ESceneComposer.hpp>

class MySecondComponent : public Engine::EComponent{
    void Update(Engine::EEntity* entity) override{
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            for (int i = 0; i < 10; ++i) {
                Engine::EEntity* new_entity = Engine::EEntityFactory("wolic", entity->GetScene())
                        .Rectangle(sprite)
                        .Transform(GetMousePosition().x, GetMousePosition().y, 0, 0, 2, 2)
                        .RigidBody().Get();

                new_entity->GetComponent<Engine::ERigidBody>()->speed_x = (float)GetRandomValue(-100, 100);
                new_entity->GetComponent<Engine::ERigidBody>()->speed_y = (float)GetRandomValue(-100, 100);

                new_entity->GetComponent<Engine::ERectangle>()->sprite.color = {(unsigned char)GetRandomValue(0, 255),
                                                                                (unsigned char)GetRandomValue(0, 255),
                                                                                (unsigned char)GetRandomValue(0, 255),
                                                                                (unsigned char)GetRandomValue(0, 255)};

                Engine::ESceneComposer(entity->GetScene()).AddTo(entity, new_entity,
                                                                 true, true, true);
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
        Engine::EWindow window("Build And Program", true);

        S_LOG_LEVEL_INFO;

        Engine::EScene scene;
        Engine::ESceneComposer composer(scene);

        composer.Add(Engine::EEntityFactory("Background", scene).Background(WHITE).Get(),
                     true, false, true);


        composer.Add(Engine::EEntityFactory("Spawner", scene).Transform(10, 40)
                .Add(new MyThirdComponent())
                .Add(new MySecondComponent())
                .Get(), true, true, true);

        composer.Add(Engine::EEntityFactory("FPS", scene).Transform(10, 10).FPSLabel().Get(),
                     true, true, true);

        Engine::EEngine engine(scene, window);
        engine.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
