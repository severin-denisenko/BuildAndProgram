//
// Created by Severin on 18.02.2023.
//

#include "ECreator.hpp"

namespace Engine {
    void ECreator::Add(Engine::EEntity *entity) {
        creating.push_back(entity);
    }

    void ECreator::Create() {
        while (!creating.empty()){
            creating.back()->Create();
            creating.pop_back();
        }
    }
} // Engine