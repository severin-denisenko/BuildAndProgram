//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_ETILING_HPP
#define BUILDANDPROGRAMM_ETILING_HPP

#include "EComponent.hpp"
#include "ETileMap.hpp"

namespace Engine {

    class ETiling : public EComponent{
    public:
        explicit ETiling(ETileMap &tileMap) : tileMap(tileMap) {}

        void Render2D(EEntity* entity) override{
            tileMap.Render();
        }

        ETileMap &tileMap;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ETILING_HPP
