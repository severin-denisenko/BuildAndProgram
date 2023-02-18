//
// Created by Severin on 15.02.2023.
//

#include "EScene.hpp"

namespace Engine {
    EScene::EScene() : root(new Engine::EEntity("Root", *this)) {
    }
} // engine