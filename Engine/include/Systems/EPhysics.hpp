//
// Created by Severin on 19.02.2023.
//

#ifndef BUILDANDPROGRAMM_EPHYSICS_HPP
#define BUILDANDPROGRAMM_EPHYSICS_HPP

#include <vector>

namespace Engine {
    class EEntity;

    class EPhysics {
    public:
        EPhysics() = default;

        void Add(EEntity* entity);
        void Remove(EEntity* entity);

        void SolvePhysics();

    private:
        void TestCollisions(EEntity* entity1, EEntity* entity2);

        std::vector<EEntity*> entities;
    };

} // Engine

#endif //BUILDANDPROGRAMM_EPHYSICS_HPP
