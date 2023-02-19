//
// Created by Severin on 16.02.2023.
//

#include "Graphics/ETexture.hpp"

namespace Engine {
    ETexture::ETexture(const std::string& filename) : texture(LoadTexture(filename.c_str())) {
    }

    const Texture2D &ETexture::Get() const {
        return texture;
    }

    ETexture::~ETexture() {
        UnloadTexture(texture);
    }
} // Engine