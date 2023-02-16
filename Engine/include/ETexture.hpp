//
// Created by Severin on 16.02.2023.
//

#ifndef BUILDANDPROGRAMM_ETEXTURE_HPP
#define BUILDANDPROGRAMM_ETEXTURE_HPP

#include <string>

#include <raylib.h>

namespace Engine {

    class ETexture {
    public:
        explicit ETexture(const std::string& filename);
        ~ETexture();

        [[nodiscard]] const Texture2D& Get() const;

    private:
        Texture2D texture;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ETEXTURE_HPP
