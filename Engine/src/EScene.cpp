//
// Created by Severin on 15.02.2023.
//

#include "EScene.hpp"

#include <utility>
#include "EEntityFactory.hpp"

namespace Engine {
    EScene::EScene(std::string name) : renderer(GetScreenWidth(), GetScreenHeight()), name(std::move(name)) {
        root = new EEntity("Root", nullptr, *this);
        root->AddComponent(std::make_unique<ETransform>());
    }

    EScene::~EScene() {
        delete root;
    }
} // engine