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

class PlayerControls: public Engine::EComponent{
public:
    void Create(Engine::EEntity* entity) override{
        transform = entity->GetComponent<Engine::ETransform>();
    }

    void Update(Engine::EEntity* entity) override{
        if (IsKeyPressed(KEY_D)){
            transform->position.x+=distance * transform->GetGlobalScale().x;
        } else if(IsKeyPressed(KEY_A)){
            transform->position.x-=distance * transform->GetGlobalScale().x;
        } else if(IsKeyPressed(KEY_S)){
            transform->position.y+=distance * transform->GetGlobalScale().y;
        } else if(IsKeyPressed(KEY_W)){
            transform->position.y-=distance * transform->GetGlobalScale().y;
        }
    }

private:
    Engine::ETransform* transform;

    float distance = 16;
};

class Application {
public:
    void Run(){
        Engine::EWindow window("Build And Program", true);

        S_LOG_LEVEL_INFO;

        Engine::EScene scene;

        Engine::ETexture texture("src/Assets/tiles.png");
        Engine::ETileSet tileSet(texture);
        tileSet.Splice(16,6);
        Engine::ETileMap tileMap(tileSet);
        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 6; ++j) {
                tileMap.Set(i, j, i * 6 + j);
            }
        }

        Engine::ETexture playerTexture("src/Assets/Characters/character7.png");
        Engine::ETileSet playerTileSet(playerTexture);
        playerTileSet.Splice(2, 1);
        playerTileSet.origin = {0, 0};

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Background", scene.root, scene)
                                  .Background(BLACK).Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("FPS", scene.root, scene)
                                  .Transform(10, 10)
                                  .FPSLabel().Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Tiles", scene.root, scene)
                                          .Transform(0, 0, 0, 0, 4, 4)
                                          .Tiling(tileMap).Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Player", scene.root, scene)
                                          .Transform(0, 0, 0, 0, 4, 4)
                                          .SlideShow(playerTileSet)
                                          .Add(new PlayerControls())
                                          .Get());

        Engine::EEngine engine(scene, window);
        engine.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
