//
// Created by Severin on 18.02.2023.
//

#ifndef BUILDANDPROGRAMM_EGAME_HPP
#define BUILDANDPROGRAMM_EGAME_HPP

#include "EScene.hpp"
#include "EWindow.hpp"

#include <list>

namespace Engine {

    class EGame {
    public:
        explicit EGame(EWindow& window) : window(window) {}

        void AddScene(EScene* scene);
        void Run();
        void LoadScene(const std::string& name);

        void EndGame();
    private:
        bool shouldEndGame = false;
        std::list<EScene*> scenes;
        EWindow& window;
    };

} // Engine

#endif //BUILDANDPROGRAMM_EGAME_HPP
