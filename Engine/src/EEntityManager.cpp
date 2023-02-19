//
// Created by Severin on 19.02.2023.
//

#include "EEntityManager.hpp"
#include "EEntity.hpp"
#include "SLib/SLog.hpp"

void Engine::EEntityManager::Delete(Engine::EEntity *entity) {
    auto i = std::find(entities.begin(), entities.end(), entity);

    if (i == entities.end())
        S_ERROR("Entity " + entity->name + " cannot be deleted from Entity manager!");

    entities.erase(i);

    renderer.Remove2D(entity);
    renderer.Remove3D(entity);
    renderer.RemoveUI(entity);
    updater.Remove(entity);

    while (!entity->entities.empty()){
        Delete(entities.back());
    }

    delete entity;
}

void Engine::EEntityManager::AddTo(Engine::EEntity *parent, Engine::EEntity *entity) {
    entities.push_back(entity);
    parent->AddEntity(entity);

    creator.Add(entity);
    updater.Add(entity);
    renderer.Add2D(entity);
    renderer.Add3D(entity);
    renderer.AddUI(entity);
}

void Engine::EEntityManager::Add(Engine::EEntity *entity) {
    entities.push_back(entity);

    creator.Add(entity);
    updater.Add(entity);
    renderer.Add2D(entity);
    renderer.Add3D(entity);
    renderer.AddUI(entity);
}

Engine::EEntity *Engine::EEntityManager::Create(const std::string &name) {
    auto* entity = new EEntity(name, scene);
    Add(entity);
    return entity;
}

Engine::EEntityManager::~EEntityManager() {
    while (!entities.empty()){
        delete entities.back();
        entities.pop_back();
    }
}
