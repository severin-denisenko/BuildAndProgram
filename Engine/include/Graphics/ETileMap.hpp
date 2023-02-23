//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_ETILEMAP_HPP
#define BUILDANDPROGRAMM_ETILEMAP_HPP

#include "ETileSet.hpp"

#include <fstream>

namespace Engine {

    class ETileMap {
    public:
        explicit ETileMap(ETileSet& tileSet) : tileSet(tileSet) {}

        void Resize(size_t width, size_t height){
            tiles.resize(height);

            for (auto &row: tiles) {
                row.resize(width);
            }
        }

        void Set(size_t x, size_t y, size_t tile_index){
            if (x >= tiles.size())
                tiles.resize(x + 1);
            if (y >= tiles[x].size())
                tiles[x].resize(y + 1);

            tiles[x][y] = tile_index;
        }

        void Render(float x, float y, float scale_x, float scale_y){
            for (size_t i = 0; i < tiles.size(); ++i) {
                for (size_t j = 0; j < tiles[i].size(); ++j) {
                    tileSet.Render(x + (float)i * (float)tileSet.width * scale_x,
                                   y + (float)j * (float)tileSet.height * scale_y,
                                   scale_x, scale_y, tiles[i][j]);
                }
            }
        }

        ETileSet& tileSet;
        std::vector<std::vector<size_t>> tiles;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ETILEMAP_HPP
