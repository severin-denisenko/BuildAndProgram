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

class ColliderUpdater : public Engine::EComponent{
public:
    ColliderUpdater() = default;

    void Create(Engine::EEntity* entity) override{
        transform = entity->GetComponent<Engine::ETransform>();
        collider = entity->GetComponent<Engine::ECollider2D>();
    }

    void Update(Engine::EEntity* entity) override{
        collider->rec.x = transform->x;
        collider->rec.y = transform->y;
    }

private:
    Engine::ETransform* transform;
    Engine::ECollider2D* collider;
};

class Boxes : public Engine::EComponent{
public:
    Boxes() = default;

    void Create(Engine::EEntity* entity) override{
        tileSet.Splice(6, 1);
    }

    void Update(Engine::EEntity* entity) override{
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            Engine::EEntity* new_entity = Engine::EEntityFactory("Falling",
                                                                 entity->GetScene()).RigidBody().Collider2D()
                    .Transform(GetMousePosition().x,
                               GetMousePosition().y)
                    .SlideShow(tileSet).Add(new ColliderUpdater()).Get();

            new_entity->GetComponent<Engine::ECollider2D>()->rec.width = (float)texture.Width() / 6;
            new_entity->GetComponent<Engine::ECollider2D>()->rec.height = (float)texture.Height();

            entity->GetScene().entityManager.AddTo(entity,new_entity);
            entity->GetScene().physics.Add(new_entity);
        }
    }
private:
    Engine::ETexture texture = Engine::ETexture("src/img.png");
    Engine::ETileSet tileSet = Engine::ETileSet(texture);
};

class Application {
public:
    void Run(){
        Engine::EWindow window("Build And Program", false);

        S_LOG_LEVEL_INFO;

        Engine::EScene scene;

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Background", scene)
                                  .Background(WHITE).Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("FPS", scene)
                                  .Transform(10, 10)
                                  .FPSLabel().Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Boxes", scene)
                                  .Add(new Boxes()).Get());

        Engine::EEngine engine(scene, window);
        engine.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
