//
// Created by Severin on 15.02.2023.
//

#include "EScene.hpp"
#include "EEntityFactory.hpp"

namespace Engine {
    EScene::EScene() : renderer(128, 128) {
        root = new EEntity("Root", nullptr, *this);
        root->AddComponent(new ETransform(0, 0));
    }
} // engine