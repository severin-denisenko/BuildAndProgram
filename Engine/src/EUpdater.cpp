//
// Created by Severin on 18.02.2023.
//

#include "EUpdater.hpp"

namespace Engine {
    void EUpdater::Add(Engine::EEntity *entity) {
        entities.push_back(entity);
    }

    void EUpdater::Update() {
        for (auto entity: entities) {
            entity->Update();
        }
    }
} // Engine