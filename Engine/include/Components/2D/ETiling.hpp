//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_ETILING_HPP
#define BUILDANDPROGRAMM_ETILING_HPP

#include "Components/EComponent.hpp"
#include "Graphics/ETileMap.hpp"

namespace Engine {

    class ETiling : public EComponent{
    public:
        explicit ETiling(ETileMap& tileMap) : tileMap(tileMap) {}

        void Create(EEntity* entity) override{
            transform = entity->GetComponent<ETransform>();
        }

        void Render2D(EEntity* entity) override{
            tileMap.Render(transform->GetGlobalPosition().x, transform->GetGlobalPosition().y,
                           transform->GetGlobalScale().x, transform->GetGlobalScale().y);
        }

    private:
        ETransform* transform = nullptr;
        ETileMap& tileMap;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ETILING_HPP
