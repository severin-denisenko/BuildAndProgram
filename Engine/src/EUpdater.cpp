//
// Created by Severin on 18.02.2023.
//

#include "EUpdater.hpp"
#include "EEntity.hpp"

namespace Engine {
    void EUpdater::Add(Engine::EEntity *entity) {
        entities.push_back(entity);
    }

    void EUpdater::Update() {
        for(size_t i = 0; i < entities.size(); ++i) {
            entities[i]->Update();
        }
    }

    void EUpdater::Remove(EEntity *entity) {
        auto i = std::find(entities.begin(), entities.end(), entity);
        if (i == entities.end())
            S_ERROR("Entity can't be deleted from Updater!");
        entities.erase(i);
    }
} // Engine