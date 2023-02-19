//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_ESLIDESHOW_H
#define BUILDANDPROGRAMM_ESLIDESHOW_H

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
            if (frame % frameBetweenSlides == 0){
                frame = 0;
                slide++;
                slide = slide % tileSet.Count();
            }

            tileSet.scale.x = transform->sx;
            tileSet.scale.y = transform->sy;
        }

        void Render2D(EEntity* entity) override{
            tileSet.Render(transform->x, transform->y, slide);
        }

        size_t frameBetweenSlides = 30;
    private:
        size_t slide;
        size_t frame;
        ETileSet& tileSet;
        ETransform* transform;
    };
}

#endif //BUILDANDPROGRAMM_ESLIDESHOW_H
