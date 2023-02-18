//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_EUPDATER_HPP
#define BUILDANDPROGRAMM_EUPDATER_HPP

#include <vector>

namespace Engine {
    class EEntity;

    class EUpdater {
    public:
        EUpdater() = default;

        void Add(Engine::EEntity* entity);

        void Update();

        void Remove(EEntity *pEntity);

    private:
        std::vector<EEntity*> entities;
    };

} // Engine

#endif //BUILDANDPROGRAMM_EUPDATER_HPP
