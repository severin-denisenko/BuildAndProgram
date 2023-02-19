//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_APPLICATION_H
#define BUILDANDPROGRAMM_APPLICATION_H

#include <EWindow.hpp>
#include <EScene.hpp>
#include "Graphics/ESprite.hpp"
#include <EEngine.hpp>
#include <EEntityFactory.hpp>

class Application {
public:
    void Run(){
        Engine::EWindow window("Build And Program", true);

        S_LOG_LEVEL_INFO;

        Engine::EScene scene;

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Background", scene)
                                  .Background(WHITE).Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("FPS", scene)
                                  .Transform(10, 10)
                                  .FPSLabel().Get());

        Engine::ETexture cube("src/cube_diffuse.png");

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Cube", scene)
                                  .Transform(0, 0).Model("src/cube.obj", cube).Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Grid", scene)
                                  .Grid(10, 0.1).Get());

        Engine::EEngine engine(scene, window);
        engine.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
