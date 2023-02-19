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

class Character: public Engine::EComponent{
public:
    void Create(Engine::EEntity* entity) override{
        transform = entity->GetComponent<Engine::ETransform>();

        entity->GetScene().camera2D.offset.x = (float) GetScreenWidth() / 2;
        entity->GetScene().camera2D.offset.y = (float) GetScreenHeight() / 2;
    }

    void Update(Engine::EEntity* entity) override{
        float delta = GetFrameTime() * 100;

        if (IsKeyDown(KEY_D))
            transform->x += delta;
        if (IsKeyDown(KEY_A))
            transform->x -= delta;
        if (IsKeyDown(KEY_W))
            transform->y -= delta;
        if (IsKeyDown(KEY_S))
            transform->y += delta;

        entity->GetScene().camera2D.target.x = transform->x;
        entity->GetScene().camera2D.target.y = transform->y;

        if (IsKeyReleased(KEY_Q))
            entity->GetScene().entityManager.Delete(entity);
    }

    Engine::ETransform* transform = nullptr;
};

class Application {
public:
    void Run(){
        Engine::EWindow window("Build And Program", true);

        S_LOG_LEVEL_INFO;

        Engine::EScene scene;

        Engine::ETexture tiles("src/tiles.png");
        Engine::ETileSet tilesSet(tiles);
        tilesSet.scale = {2, 2};
        tilesSet.Splice(21, 17);
        Engine::ETileMap tileMap(tilesSet);

        for (int i = 0; i < 21; ++i) {
            for (int j = 0; j < 17; ++j) {
                tileMap.Set(i, j, i * 17 + j);
            }
        }

        scene.entityManager.AddTo(scene.root, Engine::EEntityFactory("Back", scene).Transform(0, 0).Tiling(tileMap).Get());

        scene.entityManager.AddTo(scene.root, Engine::EEntityFactory("Background", scene).Background(BLACK).Get());


        scene.entityManager.AddTo(scene.root, Engine::EEntityFactory("FPS", scene).Transform(10, 10).FPSLabel().Get());

        Engine::ETexture texture("src/img.png");
        Engine::ETileSet tileSet(texture);
        tileSet.Splice(6, 1);
        Engine::ESprite sprite(texture);

        scene.entityManager.AddTo(scene.root, Engine::EEntityFactory("Character", scene).Transform(0, 0)
                             .SlideShow(tileSet).Add(new Character()).Get());

        scene.entityManager.AddTo(scene.root, Engine::EEntityFactory("Back", scene).Transform(0, -200)
                .Rectangle(sprite).Get());

        Engine::EEngine engine(scene, window);
        engine.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
