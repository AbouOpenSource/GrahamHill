//
// Created by abou on 18/11/2019.
//

#include "PolygonDraw.h"
#define NBR_POINTS 40

void PolygonDraw::onStart() {
    cout << "Start..."  << endl;
    glClearColor(1.0,1.0,1.0,1.0);
    S1 = new MyPolygon(20);
    S2 = new MyPolygon(20);
    S3 = new MyPolygon(20);

    /*
    *
    */
    S1->addVertex(Vector2D(120,40));
    S1->addVertex(Vector2D(400,160));
    S1->addVertex(Vector2D(320,400));
    S1->addVertex(Vector2D(40,80));

    /*
     *{(620,40),(820,60),(900,160),(820,400),(680,240),(540,80)}
     */
    S2->addVertex(Vector2D(620,40));
    S2->addVertex(Vector2D(820,60));
    S2->addVertex(Vector2D(900,160));
    S2->addVertex(Vector2D(820,400));
    S2->addVertex(Vector2D(680,240));
    S2->addVertex(Vector2D(540,80));

    /*
     *{(500,500),(800,600),(900,900),(400,900),(680,800),(640,650),(240,680)}
     */
    S3->addVertex(Vector2D(500,500));
    S3->addVertex(Vector2D(800,600));
    S3->addVertex(Vector2D(900,900));
    S3->addVertex(Vector2D(400,900));
    S3->addVertex(Vector2D(680,800));
    S3->addVertex(Vector2D(640,650));
    S3->addVertex(Vector2D(240,680));

vector<Vector2D> args;
    for (int i = 0; i < NBR_POINTS; ++i) {
            args.insert(args.end(),Vector2D(rand() % 400+1,rand() % 400+1));
    }

    S4 = new MyPolygon(args);


    std::cout<<S1->isConvexe()<<" S1"<<std::endl;
    std::cout<<S2->isConvexe()<<" S2"<<std::endl;
    std::cout<<S3->isConvexe()<<" S3"<<std::endl;


}

void PolygonDraw::onQuit() {
    //delete S1,S2,S3,S4;

    cout << "The end."  << endl;
}

void PolygonDraw::onDraw() {
   // S1->draw();
   // S2->draw();
    // S3->draw();

    S4->draw();

}

void PolygonDraw::onMouseDown(int button, double cx, double cy) {


    //GlutWindow::onMouseDown(button, cx, cy);
}

void PolygonDraw::onMouseMove(double cx, double cy) {





    cout << cx << "," << cy << endl;
    if(S1->isInside(Vector2D(cx,cy))){
        S1->mouseOver();
    }else{
        S1->mouseAway();
    }

    if(S2->isInside(Vector2D(cx,cy))){
        S2->mouseOver();
    }else{
        S2->mouseAway();
    }

    if(S3->isInside(Vector2D(cx,cy))){
        S3->mouseOver();
    }else{
        S3->mouseAway();
    }


    //GlutWindow::onMouseMove(cx, cy);
}
