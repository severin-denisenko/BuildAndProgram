//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_ETILESET_HPP
#define BUILDANDPROGRAMM_ETILESET_HPP

#include <vector>

#include "ESprite.hpp"

namespace Engine {

    class ETileSet {
    public:
        explicit ETileSet(const Texture& texture) : texture(texture) {
            Splice(1, 1);
        }

        void Splice(size_t i, size_t j){
            tiles.clear();

            width = (float)texture.width/(float)i;
            height = (float)texture.height/(float)j;

            for (size_t k = 0; k < i; ++k) {
                for (size_t l = 0; l < j; ++l) {
                    tiles.emplace_back(texture);
                    tiles.back().source = {width * (float)k, height * (float)l, width, height};
                    tiles.back().origin = {width / 2, height / 2};
                    tiles.back().destination = {0, 0, width, height};
                }
            }
        }

        void SetOrigin(Vector2 origin){
            for (auto& sprite: tiles) {
                sprite.origin = origin;
            }
        }

        void Render(float x, float y, float scale_x, float scale_y, size_t index){
            tiles[index].Render(x, y, scale_x, scale_y);
        }

        [[nodiscard]] size_t Count() const{
            return tiles.size();
        }

        std::vector<ESprite> tiles;
        float height;
        float width;
    private:
        const Texture& texture;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ETILESET_HPP
