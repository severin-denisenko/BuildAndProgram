//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_EUPDATER_HPP
#define BUILDANDPROGRAMM_EUPDATER_HPP

#include "EEntity.hpp"

namespace Engine {

    class EUpdater {
    public:
        EUpdater() = default;

        void Add(Engine::EEntity* entity);

        void Update();

    private:
        std::vector<Engine::EEntity*> entities;
    };

} // Engine

#endif //BUILDANDPROGRAMM_EUPDATER_HPP
