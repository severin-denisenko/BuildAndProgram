//
// Created by Severin on 15.02.2023.
//

#include "EScene.hpp"
#include "EEntityFactory.hpp"

namespace Engine {
    EScene::EScene() : renderer(GetScreenWidth(), GetScreenHeight()) {
        root = new EEntity("Root", nullptr, *this);
        root->AddComponent(std::make_unique<ETransform>());
    }

    EScene::~EScene() {
        delete root;
    }
} // engine