//
// Created by Severin on 19.02.2023.
//

#ifndef BUILDANDPROGRAMM_EMODEL_HPP
#define BUILDANDPROGRAMM_EMODEL_HPP

#include "Components/EComponent.hpp"
#include "Graphics/ETexture.hpp"

#include <raylib.h>

namespace Engine {

    class EModel : public EComponent{
    public:
        explicit EModel(const std::string& filename, const ETexture& texture) : texture(texture){
            model = LoadModel(filename.c_str());
        }

        void Create(EEntity* entity) override{
            transform = entity->GetComponent<ETransform>();
            model.materials->maps[MATERIAL_MAP_DIFFUSE].texture = texture.Get();
        }

        void Render3D(EEntity* entity) override{
            DrawModel(model, {transform->x, transform->y, transform->z}, 1.0f, WHITE);
        }

    private:
        const ETexture& texture;
        ETransform* transform;
        Model model;
    };

} // Engine

#endif //BUILDANDPROGRAMM_EMODEL_HPP
