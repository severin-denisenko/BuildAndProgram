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
            origin = {0, 0};
            Splice(1, 1);
            rotation = 0;
            scale = {1, 1};
        }

        void Splice(size_t i, size_t j){
            sources.clear();
            float height = (float)texture.Width()/(float)i;
            float width = (float)texture.Height()/(float)j;

            destination = {0, 0, width, height};

            for (size_t k = 0; k < i; ++k) {
                for (size_t l = 0; l < j; ++l) {
                    sources.push_back({width * (float)k, height * (float)l,
                                       width, height});
                }
            }
        }

        void Render(size_t index){
            DrawTexturePro(texture.Get(), sources[index], destination, origin,
                           rotation, color);
        }

        void Render(float x, float y, size_t index){
            DrawTexturePro(texture.Get(), sources[index],
                           {x, y, sources[index].width * scale.x, sources[index].height * scale.y},
                           origin, rotation, color);
        }

        [[nodiscard]] size_t Count() const{
            return sources.size();
        }

        Rectangle destination;
        float rotation;
        Vector2 origin;
        Vector2 scale;
        Color color = WHITE;
    private:
        std::vector<Rectangle> sources;
        const ETexture& texture;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ETILESET_HPP
