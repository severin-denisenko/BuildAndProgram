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
            if (y >= tiles.size())
                tiles.resize(y + 1);
            if (x >= tiles[y].size())
                tiles[y].resize(x + 1);

            tiles[y][x] = tile_index;
        }

        void Render(float x, float y, float scale_x, float scale_y){
            for (size_t i = 0; i < tiles.size(); ++i) {
                for (size_t j = 0; j < tiles[i].size(); ++j) {
                    tileSet.Render(x + (float)j * (float)tileSet.width * scale_x,
                                   y + (float)i * (float)tileSet.height * scale_y,
                                   scale_x, scale_y, tiles[i][j]);
                }
            }
        }

        void Load(const std::string& filename){
            std::ifstream input(filename);

            size_t width, height;

            input >> width >> height;

            Resize(width, height);

            for (size_t i = 0; i < height; ++i) {
                for (size_t j = 0; j < width; ++j) {
                    input >> tiles[i][j];
                }
            }
        }

        ETileSet& tileSet;
        std::vector<std::vector<size_t>> tiles;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ETILEMAP_HPP
