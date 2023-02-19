//
// Created by Severin on 18.02.2023.
//

#include "EUpdater.hpp"
#include "EEntity.hpp"

namespace Engine {
    void EUpdater::Add(EEntity *entity) {
        entities.push_back(entity);
    }

    void EUpdater::Update() {
        for(auto entity : entities) {
            entity->Update();
        }
    }

    void EUpdater::Remove(EEntity *entity) {
        auto i = std::find(entities.begin(), entities.end(), entity);
        if (i == entities.end()){
            S_ERROR("Entity can't be deleted from Updater!");
            return;
        }
        entities.erase(i);
    }
} // Engine