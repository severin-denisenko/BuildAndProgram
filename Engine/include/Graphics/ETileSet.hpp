//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_ETILESET_HPP
#define BUILDANDPROGRAMM_ETILESET_HPP

#include <vector>
#include "ETexture.hpp"

namespace Engine {

    class ETileSet {
    public:
        explicit ETileSet(const ETexture& texture) : texture(texture) {
            Splice(1, 1);
            rotation = 0;
        }

        void Splice(size_t i, size_t j){
            sources.clear();
            float height = (float)texture.Width()/(float)i;
            float width = (float)texture.Height()/(float)j;

            destination = {0, 0, width, height};
            origin = {width/2, height/2};

            for (size_t k = 0; k < i; ++k) {
                for (size_t l = 0; l < j; ++l) {
                    sources.push_back({height * (float)k, width * (float)l, height, width});
                }
            }
        }

        void Render(float x, float y, float scale_x, float scale_y, size_t index){
            DrawTexturePro(texture.Get(), sources[index],
                           {x, y, sources[index].width * scale_x, sources[index].height * scale_y},
                           {origin.x, origin.x}, rotation, color);
        }

        [[nodiscard]] size_t Count() const{
            return sources.size();
        }

        Rectangle destination;
        float rotation;
        Vector2 origin;
        Color color = WHITE;
    private:
        std::vector<Rectangle> sources;
        const ETexture& texture;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ETILESET_HPP
