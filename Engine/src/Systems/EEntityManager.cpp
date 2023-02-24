//
// Created by Severin on 19.02.2023.
//

#include "Systems/EEntityManager.hpp"
#include "EEntity.hpp"
#include "SLib/SLog.hpp"

void Engine::EEntityManager::Delete(EEntity *entity) {
    auto i = std::find(entities.begin(), entities.end(), entity);

    if (i == entities.end()){
        S_ERROR("Entity " + entity->name + " cannot be deleted from Entity manager!");
        return;
    }

    entities.erase(i);

    renderer.Remove2D(entity);
    renderer.Remove3D(entity);
    renderer.RemoveUI(entity);
    updater.Remove(entity);
    physics.Remove(entity);

    while (!entity->children.empty()){
        entity->RemoveEntity(entities.back());
        Delete(entities.back());
    }
}

void Engine::EEntityManager::AddTo(EEntity *parent, EEntity *entity) {
    entities.push_back(entity);
    parent->AddEntity(std::unique_ptr<EEntity>(entity));

    creator.Add(entity);
    updater.Add(entity);
    renderer.Add2D(entity);
    renderer.Add3D(entity);
    renderer.AddUI(entity);
    //physics.Add(entity);
}

void Engine::EEntityManager::Add(EEntity *entity) {
    entities.push_back(entity);

    creator.Add(entity);
    updater.Add(entity);
    renderer.Add2D(entity);
    renderer.Add3D(entity);
    renderer.AddUI(entity);
    //physics.Add(entity);
}

Engine::EEntityManager::~EEntityManager() {
    while (!entities.empty()){
        entities.pop_back();
    }
}
