//
// Created by Severin on 19.02.2023.
//

#ifndef BUILDANDPROGRAMM_EENTITYMANAGER_HPP
#define BUILDANDPROGRAMM_EENTITYMANAGER_HPP

#include "ERenderer.hpp"
#include "ECreator.hpp"
#include "EUpdater.hpp"

namespace Engine{
    class EScene;

    class EEntityManager {
    public:
        EEntityManager(ERenderer& renderer, EUpdater& updater, ECreator& creator, EScene& scene)
        : renderer(renderer), updater(updater), creator(creator), scene(scene) {}

        EEntity* Create(const std::string& name);

        void Add(EEntity* entity);

        void AddTo(EEntity* parent, EEntity* entity);

        void Delete(EEntity* entity);

        ~EEntityManager();

        ERenderer& renderer;
        EUpdater& updater;
        ECreator& creator;
        EScene& scene;
        std::vector<EEntity*> entities;
    };
}


#endif //BUILDANDPROGRAMM_EENTITYMANAGER_HPP