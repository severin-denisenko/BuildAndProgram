//
// Created by Severin on 15.02.2023.
//

#include "EScene.hpp"
#include "EEntityFactory.hpp"

namespace Engine {
    EScene::EScene() {
        root = EEntityFactory("Root", nullptr, *this).Get();
    }
} // engine