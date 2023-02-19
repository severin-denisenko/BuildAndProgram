//
// Created by Severin on 15.02.2023.
//

#include "EScene.hpp"

namespace Engine {
    EScene::EScene() {
        root = entityManager.Create("Root");
    }
} // engine