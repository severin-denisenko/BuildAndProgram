//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_APPLICATION_H
#define BUILDANDPROGRAMM_APPLICATION_H

#include <EWindow.hpp>
#include <EScene.hpp>
#include <Graphics/ESprite.hpp>
#include <EEngine.hpp>
#include <EEntityFactory.hpp>

class Boxes : public Engine::EComponent{
public:
    Boxes() = default;

    void Create(Engine::EEntity* entity) override{
        tileSet.Splice(1, 1);
    }

    void Update(Engine::EEntity* entity) override{
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            Engine::EEntity* new_entity = Engine::EEntityFactory(
                    "Falling",
                    entity,
                    entity->GetScene()
                    ).RigidBody()
                            .Collider2D()
                            .Transform(GetMousePosition().x,GetMousePosition().y, 0, 0, 0.5, 0.5)
                            .SlideShow(tileSet).Get();

            new_entity->GetComponent<Engine::ECollider2D>()->rec.width = (float)texture.Width();
            new_entity->GetComponent<Engine::ECollider2D>()->rec.height = (float)texture.Height();

            entity->GetScene().entityManager.AddTo(entity,new_entity);
            entity->GetScene().physics.Add(new_entity);
        }
    }
private:
    Engine::ETexture texture = Engine::ETexture("src/cube_diffuse.png");
    Engine::ETileSet tileSet = Engine::ETileSet(texture);
};

class Application {
public:
    void Run(){
        Engine::EWindow window("Build And Program", false);

        S_LOG_LEVEL_INFO;

        Engine::EScene scene;

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Background", scene.root, scene)
                                  .Background(WHITE).Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("FPS", scene.root, scene)
                                  .Transform(10, 10)
                                  .FPSLabel().Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Boxes", scene.root, scene)
                                          .Transform(0, 0)
                                          .Add(new Boxes()).Get());

        Engine::EEngine engine(scene, window);
        engine.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
