//
// Created by Severin on 17.02.2023.
//

#include "ESprite.hpp"

namespace Engine {
    ESprite::ESprite(const ETexture& texture) : source({0, 0, (float)texture.Get().width, (float)texture.Get().height})
            , origin({0, 0})
            , texture(texture)
    {
    }

    void ESprite::Render() {
        DrawTexturePro(texture.Get(), source, destination, origin,
                       rotation, WHITE);
    }
} // Engine
