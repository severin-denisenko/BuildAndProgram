//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_ECREATOR_HPP
#define BUILDANDPROGRAMM_ECREATOR_HPP

#include <vector>

namespace Engine {
    class EEntity;

    class ECreator {
    public:
        ECreator() = default;

        void Add(EEntity *entity);

        void Create();

    private:
        std::vector<EEntity*> creating;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ECREATOR_HPP
