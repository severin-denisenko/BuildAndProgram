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

        void Add(EEntity* entity, bool create, bool update, bool render){
            scene.root->AddEntity(entity);

            if(create)
                scene.creator.Add(entity);
            if (update)
                scene.updater.Add(entity);
            if(render)
                scene.renderer.Add2D(entity);
        }

        void AddTo(EEntity* parent, EEntity* entity, bool create, bool update, bool render){
            parent->AddEntity(entity);

            if(create)
                scene.creator.Add(entity);
            if (update)
                scene.updater.Add(entity);
            if(render)
                scene.renderer.Add2D(entity);
        }
    private:
        EScene& scene;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ESCENECOMPOSER_HPP
