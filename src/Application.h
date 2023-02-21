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

#include <array>

class PlayerAControls: public Engine::EComponent{
public:
    void Create(Engine::EEntity* entity) override{
        transform = entity->GetComponent<Engine::ETransform>();
    }

    void Update(Engine::EEntity* entity) override{
        if (IsKeyPressed(KEY_D) && transform->position.x < distance * 6){
            transform->position.x+=distance * transform->GetGlobalScale().x;
        } else if(IsKeyPressed(KEY_A) && transform->position.x > distance){
            transform->position.x-=distance * transform->GetGlobalScale().x;
        } else if(IsKeyPressed(KEY_S) && transform->position.y < distance * 5){
            transform->position.y+=distance * transform->GetGlobalScale().y;
        } else if(IsKeyPressed(KEY_W) && transform->position.y >= distance){
            transform->position.y-=distance * transform->GetGlobalScale().y;
        }
    }

private:
    Engine::ETransform* transform;

    float distance = 16;
};

class PlayerBControls: public Engine::EComponent{
public:
    void Create(Engine::EEntity* entity) override{
        transform = entity->GetComponent<Engine::ETransform>();
    }

    void Update(Engine::EEntity* entity) override{
        if (IsKeyPressed(KEY_RIGHT) && transform->position.x < distance * 6){
            transform->position.x+=distance * transform->GetGlobalScale().x;
        } else if(IsKeyPressed(KEY_LEFT) && transform->position.x > distance){
            transform->position.x-=distance * transform->GetGlobalScale().x;
        } else if(IsKeyPressed(KEY_DOWN) && transform->position.y < distance * 5){
            transform->position.y+=distance * transform->GetGlobalScale().y;
        } else if(IsKeyPressed(KEY_UP) && transform->position.y >= distance){
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
        Engine::EWindow window("Build And Program", false);

        S_LOG_LEVEL_INFO;

        Engine::EScene scene;

        scene.renderer.ChangeResolution(128, 128);

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

        Engine::ETileSet playerATiles(characters.Get(Characters::Knight_pink));
        playerATiles.Splice(2, 1);
        playerATiles.SetOrigin({0, 0});

        Engine::ETileSet playerBTiles(characters.Get(Characters::Knight_orange));
        playerBTiles.Splice(2, 1);
        playerBTiles.SetOrigin({0, 0});

        //////

        Texture backgroundTexture = LoadTexture("src/Assets/background.png");
        Engine::ESprite backgroundSprite(backgroundTexture);
        backgroundSprite.origin = {0, 0};

        Texture doorsTexture = LoadTexture("src/Assets/doors.png");
        Engine::ETileSet doorsTileSet(doorsTexture);
        doorsTileSet.Splice(2, 2);
        doorsTileSet.SetOrigin({0, 0});
        Engine::ETileMap doorsTileMap(doorsTileSet);
        doorsTileMap.Set(3, 0, 0);
        doorsTileMap.Set(4, 0, 2);

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Background", scene.root, scene)
                                  .Background(BLACK).Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Tiles", scene.root, scene)
                                          .Transform(0, 0, 0, 0, 1, 1)
                                          .Rectangle(backgroundSprite)
                                          .Tiling(doorsTileMap).Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("PlayerA", scene.root, scene)
                                          .Transform(16, 0, 0, 0, 1, 1)
                                          .SlideShow(playerATiles)
                                          .Add(new PlayerAControls())
                                          .Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("PlayerB", scene.root, scene)
                                          .Transform(16, 0, 0, 0, 1, 1)
                                          .SlideShow(playerBTiles)
                                          .Add(new PlayerBControls())
                                          .Get());

        Engine::EEngine engine(scene, window);
        engine.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
