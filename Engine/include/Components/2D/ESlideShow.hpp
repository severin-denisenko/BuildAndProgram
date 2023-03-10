//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_ESLIDESHOW_HPP
#define BUILDANDPROGRAMM_ESLIDESHOW_HPP

#include "Components/EComponent.hpp"
#include "Graphics/ETileSet.hpp"

namespace Engine{
    class ESlideShow : public EComponent{
    public:
        explicit ESlideShow(ETileSet& tileSet): tileSet(tileSet) {}

        void Create(EEntity* entity) override{
            transform = entity->GetComponent<ETransform>();
            S_INFO("Component ESlideShow created.");
        }

        void Update(EEntity* entity) override{
            frame++;
            if (frame % frameBetweenSlides == 0)
                slide++;
        }

        void Render2D(EEntity* entity) override{
            tileSet.Render(transform->GetGlobalPosition().x, transform->GetGlobalPosition().y,
                           transform->GetGlobalScale().x, transform->GetGlobalScale().y,
                           slide % tileSet.Count());
        }

        size_t frameBetweenSlides = 30;

        ETileSet& tileSet;
    private:
        size_t frame = 0;
        size_t slide = 0;
        ETransform* transform;
    };
}

#endif //BUILDANDPROGRAMM_ESLIDESHOW_HPP
