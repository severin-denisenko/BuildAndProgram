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

        Engine::ETexture cube("src/cube_diffuse.png");
        Engine::EMesh mesh("src/cube.obj");
        mesh.SetTexture(cube);

        for (int i = -10; i < 10; ++i) {
            for (int j = -10; j < 10; ++j) {
                scene.entityManager.AddTo(scene.root,
                                          Engine::EEntityFactory("Cube", scene)
                                                  .Transform(i * 2, 0, j * 2).Model(mesh).Get());
            }
        }

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("Grid", scene)
                                  .Grid(10, 1).Get());

        scene.entityManager.AddTo(scene.root,
                                  Engine::EEntityFactory("CameraController", scene)
                                  .CameraController3D().Get());

        Engine::EEngine engine(scene, window);
        engine.Run();
    }
};


#endif //BUILDANDPROGRAMM_APPLICATION_H
