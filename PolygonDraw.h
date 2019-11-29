//
// Created by abou on 18/11/2019.
//

#ifndef RECTANGLES_POLYGONDRAW_H
#define RECTANGLES_POLYGONDRAW_H

#include <iostream>
#include <cstdlib>
#include <glutWindow.h>
#include "Vector2D.h"
#include "MyPolygon.h"
using namespace std;

class PolygonDraw: public GlutWindow {
public:
    MyPolygon *S1,*S2, *S3,*S4;

public:
    PolygonDraw(const string &title,int argc,char **argv):GlutWindow(argc,argv,title,1000,1000,FIXED) {
    };

    void onMouseMove(double cx,double cy) override;
    void onMouseDown(int button,double cx,double cy) override;
    void onStart() override;
    void onDraw() override;
    void onQuit() override;
   };

#endif //RECTANGLES_POLYGONDRAW_H
