//
// Created by Severin on 19.02.2023.
//

#ifndef BUILDANDPROGRAMM_EMESH_H
#define BUILDANDPROGRAMM_EMESH_H

#include <string>

#include <raylib.h>

#include "ETexture.hpp"

namespace Engine {

    class EMesh {
    public:
        explicit EMesh(const std::string& filename){
            model = LoadModel(filename.c_str());
        }

        void SetTexture(ETexture& texture){
            model.materials->maps[MATERIAL_MAP_DIFFUSE].texture = texture.Get();
        }

        [[nodiscard]] const Model& Get() const{
            return model;
        }

        Model model;
    };

} // Engine

#endif //BUILDANDPROGRAMM_EMESH_H
