//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_ESCENECOMPOSER_HPP
#define BUILDANDPROGRAMM_ESCENECOMPOSER_HPP

#include "EScene.hpp"
#include "EEntity.hpp"

namespace Engine {

    class ESceneComposer {
    public:
        explicit ESceneComposer(EScene& scene): scene(scene) {}

        void Add(EEntity* entity){
            scene.root->AddEntity(entity);

            scene.creator.Add(entity);
            scene.updater.Add(entity);
            scene.renderer.Add2D(entity);
            scene.renderer.AddUI(entity);
        }

        void Remove(EEntity* entity){
            scene.renderer.Remove2D(entity);
            scene.renderer.RemoveUI(entity);
            scene.updater.Remove(entity);
        }

        void AddTo(EEntity* parent, EEntity* entity){
            parent->AddEntity(entity);

            scene.creator.Add(entity);
            scene.updater.Add(entity);
            scene.renderer.Add2D(entity);
            scene.renderer.AddUI(entity);
        }
    private:
        EScene& scene;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ESCENECOMPOSER_HPP
