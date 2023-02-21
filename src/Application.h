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
#include <Systems/ETextureHolder.hpp>

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

        enum class Characters{
            Knight_pink,
            Knight_orange,
            Wanderer_male,
            Wanderer_female,
            Wizard_male,
            Wizard_female,
            Dino_red,
            Dino_green
        };

        Engine::ETextureHolder<Characters> characters;

        characters.Load(Characters::Knight_pink, "src/Assets/Characters/1.png");
        characters.Load(Characters::Knight_orange, "src/Assets/Characters/2.png");
        characters.Load(Characters::Wanderer_male, "src/Assets/Characters/3.png");
        characters.Load(Characters::Wanderer_female, "src/Assets/Characters/4.png");
        characters.Load(Characters::Wizard_male, "src/Assets/Characters/5.png");
        characters.Load(Characters::Wizard_female, "src/Assets/Characters/6.png");
        characters.Load(Characters::Dino_red, "src/Assets/Characters/7.png");
        characters.Load(Characters::Dino_green, "src/Assets/Characters/8.png");

        Engine::ETileSet playerTileSet(characters.Get(Characters::Dino_green));
        playerTileSet.Splice(2, 1);
        playerTileSet.SetOrigin({0, 0});

        Texture texture = LoadTexture("src/Assets/tiles.png");
        Engine::ETileSet tileSet(texture);
        tileSet.Splice(6,16);
        Engine::ETileMap tileMap(tileSet);
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 16; ++j) {
                tileMap.Set(i, j, i * 16 + j);
            }
        }
        tileSet.SetOrigin({0, 0});

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
