//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_APPLICATION_H
#define BUILDANDPROGRAMM_APPLICATION_H

#include <EWindow.hpp>
#include <EScene.hpp>
#include <Graphics/ESprite.hpp>
#include <EGame.hpp>
#include <EEntityFactory.hpp>
#include <Systems/ETextureHolder.hpp>
#include <EAnimation.h>

class LevelLoader: public Engine::EComponent{
public:
    LevelLoader() = default;

    void Create(Engine::EEntity* entity) override{
        button = entity->GetComponent<Engine::EButton>();
    }

    void Update(Engine::EEntity* entity) override{
        if (button->action == Engine::EButton::RELEASED){
            entity->GetScene().game->LoadScene("Main");
        }
    }

private:
    Engine::EButton* button = nullptr;
};

class GameExit: public Engine::EComponent{
public:
    GameExit() = default;

    void Create(Engine::EEntity* entity) override{
        button = entity->GetComponent<Engine::EButton>();
    }

    void Update(Engine::EEntity* entity) override{
        if (button->action == Engine::EButton::RELEASED){
            entity->GetScene().game->EndGame();
        }
    }

private:
    Engine::EButton* button = nullptr;
};

class PlayerController : public Engine::EComponent{
public:
    void Create(Engine::EEntity* entity) override{
        transform = entity->GetComponent<Engine::ETransform>();
        collider2D = entity->GetComponent<Engine::ECollider2D>();

        collider2D->rec = {0, 0, distance, distance};

        moveAnimationX = Engine::EAnimation<float>(&transform->position.x);
        moveAnimationY = Engine::EAnimation<float>(&transform->position.y);

        entity->GetScene().physics.Add(entity);
    }

    void Update(Engine::EEntity* entity) override{
        if (moveAnimationX.Started() && !moveAnimationX.Ended()){
            moveAnimationX.Step();
            return;
        }
        if (moveAnimationY.Started() && !moveAnimationY.Ended()){
            moveAnimationY.Step();
            return;
        }

        int animationFrames = 4;

        if (IsKeyPressed(key_right) && transform->position.x < distance * 6){
            moveAnimationX.Start(transform->position.x,
                                 transform->position.x + distance * transform->GetGlobalScale().x,
                                 animationFrames);
        } else if(IsKeyPressed(key_left) && transform->position.x > distance){
            moveAnimationX.Start(transform->position.x,
                                 transform->position.x - distance * transform->GetGlobalScale().x,
                                 animationFrames);
        } else if(IsKeyPressed(key_down) && transform->position.y < distance * 7){
            moveAnimationY.Start(transform->position.y,
                                 transform->position.y + distance * transform->GetGlobalScale().y,
                                 animationFrames);
        } else if(IsKeyPressed(key_up) && transform->position.y > 2 * distance){
            moveAnimationY.Start(transform->position.y,
                                 transform->position.y - distance * transform->GetGlobalScale().y,
                                 animationFrames);
        }
    }

    int key_up = KEY_W;
    int key_down = KEY_S;
    int key_left = KEY_A;
    int key_right = KEY_D;
protected:
    Engine::ETransform* transform;
    Engine::ECollider2D* collider2D;
    Engine::EAnimation<float> moveAnimationX;
    Engine::EAnimation<float> moveAnimationY;

    float distance = 16;
};

class PlayerAControls: public PlayerController{
public:
    void Create(Engine::EEntity* entity) override{
        PlayerController::Create(entity);
    }
};

class PlayerBControls: public PlayerController{
public:
    void Create(Engine::EEntity* entity) override{
        PlayerController::Create(entity);

        key_up = KEY_UP;
        key_down = KEY_DOWN;
        key_left = KEY_LEFT;
        key_right = KEY_RIGHT;
    }
};

class Application {
public:
    void Run(){
        Engine::EWindow window("Build And Program", false);

        S_LOG_LEVEL_INFO;

        Engine::EScene scene("Main");

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
        playerATiles.SetOrigin({0, (float)characters.Get(Characters::Knight_pink).height});

        Engine::ETileSet playerBTiles(characters.Get(Characters::Knight_orange));
        playerBTiles.Splice(2, 1);
        playerBTiles.SetOrigin({0, (float)characters.Get(Characters::Knight_orange).height});

        //////

        Texture tileSetTexture = LoadTexture("src/Assets/tileset.png");
        Engine::ETileSet tileSet(tileSetTexture);
        tileSet.Splice(10, 10);
        tileSet.SetOrigin({0, 0});
        Engine::ETileMap tileMap(tileSet);
        tileMap.Load("src/Assets/back_layer.tiles");
        Engine::ETileMap tileMapProps(tileSet);
        tileMapProps.Load("src/Assets/front_layer.tiles");

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Background", scene.root, scene)
                                  .Background(BLACK).Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Tiles", scene.root, scene)
                                          .Transform(0, 0, 0, 0, 1, 1)
                                          .Tiling(tileMap)
                                          .Tiling(tileMapProps).Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("PlayerA", scene.root, scene)
                                          .Transform(16, 32 + 16, 0, 0, 1, 1)
                                          .SlideShow(playerATiles)
                                          .Collider2D(Engine::ECollider2D::RECTANGLE)
                                          .Add(new PlayerAControls())
                                          .Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("PlayerB", scene.root, scene)
                                          .Transform(128 - 32, 32 + 16, 0, 0, 1, 1)
                                          .SlideShow(playerBTiles)
                                          .Collider2D(Engine::ECollider2D::RECTANGLE)
                                          .Add(new PlayerBControls())
                                          .Get());


        /// Other scene

        Engine::EScene menu("Menu");

        Texture buttonTexture = LoadTexture("src/Assets/button1.png");
        Engine::ETileSet buttonSet(buttonTexture);
        buttonSet.Splice(1, 3);
        buttonSet.SetOrigin({0, 0});

        Engine::ETileMap tileMapMenu(tileSet);
        tileMapMenu.Load("src/Assets/menu.tiles");

        menu.renderer.ChangeResolution(128, 128);

        menu.entityManager.AddTo(menu.root,
                                  Engine::EEntityFactory("Button", menu.root, menu)
                                          .Transform(300, 300, 0, 0, 10, 10)
                                          .Button(buttonSet)
                                          .Add(new LevelLoader()).Get());

        menu.entityManager.AddTo(menu.root,
                                  Engine::EEntityFactory("Background", menu.root, menu)
                                          .Background(BLACK).Get());

        menu.entityManager.AddTo(menu.root,
                                 Engine::EEntityFactory("Background", menu.root, menu)
                                 .Transform()
                                 .Tiling(tileMapMenu).Get());

        Engine::EGame engine(window);
        engine.AddScene(&menu);
        engine.AddScene(&scene);
        engine.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
