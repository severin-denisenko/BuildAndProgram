//
// Created by Severin on 21.02.2023.
//

#ifndef BUILDANDPROGRAMM_ETEXTUREHOLDER_HPP
#define BUILDANDPROGRAMM_ETEXTUREHOLDER_HPP

#include "Graphics/ETileSet.hpp"

#include <map>

namespace Engine {

    template<typename Id>
    class ETextureHolder {
    public:
        ETextureHolder() = default;

        void Load(Id id, const std::string& filename);
        Texture& Get(Id id);
    private:
        std::map<Id, Texture> resources;
    };

    template<typename Id>
    void ETextureHolder<Id>::Load(Id id, const std::string& filename) {
        resources[id] = LoadTexture(filename.c_str());
    }

    template<typename Id>
    Texture &ETextureHolder<Id>::Get(Id id) {
        return resources[id];
    }


} // Engine

#endif //BUILDANDPROGRAMM_ETEXTUREHOLDER_HPP
