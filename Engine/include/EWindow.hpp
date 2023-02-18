//
// Created by Severin on 15.02.2023.
//

#ifndef BUILDANDPROGRAMM_EWINDOW_HPP
#define BUILDANDPROGRAMM_EWINDOW_HPP

#include <string>

namespace Engine{
    class EWindow {
    public:
        explicit EWindow(const char* name);
        ~EWindow();

        bool Open();
    };
}

#endif //BUILDANDPROGRAMM_EWINDOW_HPP
