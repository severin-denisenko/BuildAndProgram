//
// Created by Severin on 19.02.2023.
//

#include "Systems/EEntityManager.hpp"
#include "EEntity.hpp"
#include "SLib/SLog.hpp"

void Engine::EEntityManager::AddTo(EEntity *parent, EEntity *entity) {
    entities.push_back(entity);
    parent->AddEntity(std::unique_ptr<EEntity>(entity));

    creator.Add(entity);
    updater.Add(entity);
    renderer.Add2D(entity);
    renderer.Add3D(entity);
    renderer.AddUI(entity);
    // physics.Add(entity);
}
