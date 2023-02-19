//
// Created by Severin on 19.02.2023.
//

#ifndef BUILDANDPROGRAMM_ECAMERACONTROLLER3D_HPP
#define BUILDANDPROGRAMM_ECAMERACONTROLLER3D_HPP

#include "Components/EComponent.hpp"
#include "EScene.hpp"

#include <raylib.h>

namespace Engine {

    class ECameraController3D : public EComponent{
    public:
        void Create(EEntity* entity) override{
            camera = &entity->GetScene().camera3D;
            HideCursor();
        }

        void Update(EEntity* entity) override{
            UpdateCamera(camera, CAMERA_FIRST_PERSON);
            SetMousePosition(GetScreenWidth()/2, GetScreenHeight()/2);
        }

    private:
        Camera* camera;
    };

} // Engine

#endif //BUILDANDPROGRAMM_ECAMERACONTROLLER3D_HPP
