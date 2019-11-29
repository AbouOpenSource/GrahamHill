//
// Created by abou on 25/11/2019.
//

#ifndef RECTANGLES_TRIANGLE_H
#define RECTANGLES_TRIANGLE_H


#include "Vector2D.h"
#include <vector>
#include <array>

class Triangle {
public:
    Triangle(Vector2D *ptr1, Vector2D *ptr2, Vector2D *ptr3);
    std::array<Vector2D *,3> ptr;
    //Vector2D *ptr[3];

    bool isOnTheLeft(Vector2D *P, Vector2D *P1, Vector2D *P2);
    bool isEmpty(const std::vector<Vector2D *> &tmp, int n);
    bool isInside(Vector2D *p);
};


#endif //RECTANGLES_TRIANGLE_H
