//
// Created by Severin on 19.02.2023.
//

#include "Systems/EPhysics.hpp"
#include "EEntity.hpp"
#include "Components/Physics/ECollider2D.hpp"
#include <raylib.h>

namespace Engine {
    void EPhysics::Add(EEntity *entity) {
        entities.push_back(entity);
    }

    void EPhysics::Remove(EEntity *entity) {
        auto i = std::find(entities.begin(), entities.end(), entity);
        if (i == entities.end()){
            S_ERROR("Entity " + entity->name + " can't be deleted from 2D Renderer!");
            return;
        }
        entities.erase(i);
    }

    void EPhysics::SolvePhysics() {
        for (size_t i = 0; i < entities.size(); ++i) {
            for (size_t j = 0; j < entities.size(); ++j) {
                if (i == j)
                    continue;
                TestCollisions(entities[i], entities[j]);
            }
        }
    }

    void EPhysics::TestCollisions(EEntity *entity1, EEntity *entity2) {
        auto* collider1 = entity1->GetComponent<ECollider2D>();
        auto* collider2 = entity2->GetComponent<ECollider2D>();

        if (collider1 == nullptr){
            S_ERROR("Can't find collider on object " + entity1->name + ".");
            return;
        }
        if (collider2 == nullptr){
            S_ERROR("Can't find collider on object " + entity2->name + ".");
            return;
        }

        ECollider2D::ECollider2DShape shape1 = collider1->shape;
        ECollider2D::ECollider2DShape shape2 = collider2->shape;

        bool res = false;

        if (shape1 == ECollider2D::RECTANGLE && shape2 == ECollider2D::RECTANGLE){
            res = CheckCollisionRecs(collider1->rec, collider2->rec);
        } else if(shape1 == ECollider2D::CIRCLE && shape2 == ECollider2D::CIRCLE){
            res = CheckCollisionCircles(collider1->center, collider1->radius,
                                  collider2->center, collider2->radius);
        } else if(shape1 == ECollider2D::CIRCLE && shape2 == ECollider2D::RECTANGLE){
            res = CheckCollisionCircleRec(collider1->center,
                                          collider1->radius, collider2->rec);
        } else if(shape1 == ECollider2D::RECTANGLE && shape2 == ECollider2D::CIRCLE){
            res = CheckCollisionCircleRec(collider2->center,
                                          collider2->radius, collider1->rec);
        } else if(shape1 == ECollider2D::RECTANGLE && shape2 == ECollider2D::POINT){
            res = CheckCollisionPointRec(collider2->point, collider1->rec);
        } else if(shape1 == ECollider2D::POINT && shape2 == ECollider2D::RECTANGLE){
            res = CheckCollisionPointRec(collider1->point, collider2->rec);
        } else if(shape1 == ECollider2D::CIRCLE && shape2 == ECollider2D::POINT){
            res = CheckCollisionPointCircle(collider2->point, collider1->center, collider1->radius);
        } else if(shape1 == ECollider2D::POINT && shape2 == ECollider2D::CIRCLE){
            res = CheckCollisionPointCircle(collider1->point, collider2->center, collider2->radius);
        } else if(shape1 == ECollider2D::TRIANGLE && shape2 == ECollider2D::POINT){
            res = CheckCollisionPointTriangle(collider2->point, collider1->p1, collider1->p2, collider1->p3);
        } else if(shape1 == ECollider2D::POINT && shape2 == ECollider2D::TRIANGLE){
            res = CheckCollisionPointTriangle(collider1->point, collider2->p1, collider2->p2, collider2->p3);
        } else if(shape1 == ECollider2D::LINE && shape2 == ECollider2D::LINE){
            Vector2 point;
            res = CheckCollisionLines(collider1->l1, collider1->l2, collider2->l1, collider2->l2, &point);
        } else if(shape1 == ECollider2D::LINE && shape2 == ECollider2D::POINT){
            int threshold = 0;
            res = CheckCollisionPointLine(collider2->point, collider1->p1, collider1->p2, threshold);
        } else if(shape1 == ECollider2D::POINT && shape2 == ECollider2D::LINE){
            int threshold = 0;
            res = CheckCollisionPointLine(collider1->point, collider2->p1, collider2->p2, threshold);
        }

        if(res){
            S_INFO("Collision!");
        }

        collider1->colliding = res;
        collider2->colliding = res;
    }
} // Engine