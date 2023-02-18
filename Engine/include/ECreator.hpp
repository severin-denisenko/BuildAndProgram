//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_ECREATOR_HPP
#define BUILDANDPROGRAMM_ECREATOR_HPP

#include "EEntity.hpp"

namespace Engine {

    class ECreator {
    public:
        ECreator() = default;

        void Add(Engine::EEntity *entity);

        void Create();

    private:
        std::vector<Engine::EEntity*> creating;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ECREATOR_HPP
