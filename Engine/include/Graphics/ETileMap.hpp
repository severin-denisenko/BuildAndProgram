//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_ETILEMAP_HPP
#define BUILDANDPROGRAMM_ETILEMAP_HPP

#include "ETileSet.hpp"

namespace Engine {

    class ETileMap {
    public:
        explicit ETileMap(ETileSet& tileSet) : tileSet(tileSet) {}

        void Set(size_t x, size_t y, size_t tile_index){
            tiles.emplace_back(x, y, tile_index);
        }

        void Render(float scale_x, float scale_y){
            for (auto tile: tiles) {
                auto [x, j, k] = tile;
                tileSet.Render((float)x * tileSet.destination.height, (float)j * tileSet.destination.width,
                                scale_x, scale_y, k);
            }
        }

        ETileSet& tileSet;
        std::vector<std::tuple<size_t,size_t,size_t>> tiles;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ETILEMAP_HPP
