//
// Created by abou on 18/11/2019.
//

#ifndef RECTANGLES_MYPOLYGON_H
#define RECTANGLES_MYPOLYGON_H

#include "Vector2D.h"
#include "Triangle.h"
#include <glutWindow.h>
#include <vector>

class MyPolygon {

    Vector2D * tabPts;

    std::vector<Triangle> ptsTriangle;
    std::vector<Vector2D> all_points;
    //std::vector<Vector2D> ptsTriangulation;
        int Nmax;
        int N;

public :
    MyPolygon(int nmax);

    virtual ~MyPolygon();

    bool addVertex(const Vector2D &item);

    void draw();

    bool isConvexe();

    bool isOnTheLeft(const Vector2D &p,int i);
    bool isOnTheLeft(const Vector2D *p, const Vector2D *p1, const Vector2D *p2);


    bool isInside(Vector2D p);

    void mouseOver();

    void mouseAway();

    void triangulation();

    bool isEmpty(const vector<Vector2D*> &tmp, int n);

    bool graHam(std::vector<Vector2D&> tmp);

   // bool isOnTheLeft(Vector2D *P, Vector2D *P1, Vector2D *P2);
    MyPolygon(vector<Vector2D> &points);
};


#endif //RECTANGLES_MYPOLYGON_H
