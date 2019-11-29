//
// Created by abou on 18/11/2019.
//

#include <algorithm>
#include <stack>
#include "MyPolygon.h"

MyPolygon::MyPolygon(int nmax) : Nmax(nmax) {
    ptsTriangle=vector<Triangle>();
    tabPts = new Vector2D[nmax];
    N=0;
}


bool polarComparaison(Vector2D P1, Vector2D P2){
    double a1 = asin(P1.p_y/sqrt(P1.p_x*P1.p_x+P1.p_y*P1.p_y));
    if(P1.p_x< 0.0) a1 = M_PI -a1;
    double a2 = asin(P2.p_y/sqrt(P2.p_x*P2.p_x+P2.p_y*P2.p_y));
    if(P2.p_x< 0.0) a2 = M_PI - a2;
    return a1<a2;

}

MyPolygon::MyPolygon(vector<Vector2D> &points) {

    assert(points.size()>3);

    // To draw the polygons with all the points
    all_points = points;

    auto p = points.begin();
    auto pymin = points.begin();

    //find point with minimal y and swap with first point
    while (p!=points.end()){
        if(p->p_y < pymin->p_y){
            pymin=p;
        }
        p++;
    }
//swap

if(pymin != points.begin())
    iter_swap(points.begin(),pymin);
Vector2D origin (points.begin()->p_x,points.begin()->p_y);

//copy points in a set of points relative to point[0]

    vector<Vector2D> pointdRealtive;

    for (auto pOrig : points) {
        pointdRealtive.push_back(Vector2D(pOrig.p_x-origin.p_x,pOrig.p_y-origin.p_y));
    }

    sort(pointdRealtive.begin()+1,pointdRealtive.end(),polarComparaison);

        std::stack<Vector2D*> CHStack;

        Vector2D *top_1,*top;

    CHStack.push(&pointdRealtive[0]);
    CHStack.push(&pointdRealtive[1]);
    CHStack.push(&pointdRealtive[2]);

    vector<Vector2D>::iterator pi = pointdRealtive.begin()+3;
    while(pi!=pointdRealtive.end()){
        top = CHStack.top();
        //update values of top and top_1
        CHStack.pop();
        top_1 = CHStack.top();
        CHStack.push(top);

        while(!isOnTheLeft(&(*pi),top_1,top)){
            CHStack.pop();
            top = CHStack.top();
            CHStack.pop();
            top_1 =  CHStack.top();
            CHStack.push(top);

        }
CHStack.push(&(*pi));
        pi++;
    }

    N = CHStack.size();
    Nmax = N;
    tabPts = new Vector2D[Nmax+1];

    int i= N - 1;
    while (!CHStack.empty() && i++) {
        std::cout<<"je suis la "<<std::endl;
        tabPts[i--] = *(CHStack.top()) + origin;
        CHStack.pop();
    }
    tabPts[N] = tabPts[0];

}




MyPolygon::~MyPolygon() {
    delete [] tabPts;
}

bool MyPolygon::addVertex(const Vector2D &item) {
   /*The convex function*/
   if (N==Nmax)
       return false;
    tabPts[N++]=item;
    tabPts[N]=tabPts[0];
    return true;
}

void MyPolygon::draw() {
    triangulation();
    /*glColor3f(1.0,1.0,0.0);
        glBegin(GL_POLYGON);
            for(int i =0; i< N; i++){
                glVertex2f(tabPts[i].p_x,tabPts[i].p_y);

            }
        glEnd();

        glColor3f(0,0,0);
        glBegin(GL_LINE_LOOP);
            for(int i =0; i< N; i++){
                glVertex2f(tabPts[i].p_x,tabPts[i].p_y);
            }
        glEnd();
*/
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
    for (auto item: ptsTriangle) {
        glVertex2d(item.ptr[0]->p_x, item.ptr[0]->p_y);
        glVertex2d(item.ptr[1]->p_x, item.ptr[1]->p_y);
        glVertex2d(item.ptr[2]->p_x, item.ptr[2]->p_y);

    }
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    for (auto p:all_points) {
        GlutWindow::fillEllipse(p.p_x, p.p_y, 3, 3);
    }


    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    for (auto t:ptsTriangle) {
        glVertex2f(t.ptr[0]->p_x, t.ptr[0]->p_y);
        glVertex2f(t.ptr[1]->p_x, t.ptr[1]->p_y);
        glVertex2f(t.ptr[2]->p_x, t.ptr[2]->p_y);
    }
    glEnd();
/*
    glLineWidth(1);
    // Draw the number of points
    for (int i = 0; i < N; i++) {
        glVertex2f(tabPts[i].p_x - 10, tabPts[i].p_y - 10);
        glVertex2f(tabPts[i].p_x + 10, tabPts[i].p_y + 10);
        glVertex2f(tabPts[i].p_x + 10, tabPts[i].p_y - 10);
        glVertex2f(tabPts[i].p_x - 10, tabPts[i].p_y + 10);
        GlutWindow::drawText(tabPts[i].p_x - 10, tabPts[i].p_y, to_string(i), GlutWindow::ALIGN_RIGHT);
    }
*/
 }
bool MyPolygon::isOnTheLeft(const Vector2D &p, int i) {

    Vector2D u = tabPts[i+1]-tabPts[i];
    Vector2D v = p-tabPts[i];
    return (u.p_x*v.p_y - u.p_y* v.p_x) >= 0 ;
}

bool MyPolygon::isConvexe() {

        int index=0;
        while(index <N && isOnTheLeft(tabPts[(index+2)%N],index))
        {
           index++;
        }
    return (index<N);
}

bool MyPolygon::isInside(Vector2D p) {
    int index =0;
    while (index < N && isOnTheLeft(p,index)){
            index++;
    }
    return  (index==N);



}

void MyPolygon::mouseOver() {

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    for(int i =0; i< N; i++){
        glVertex2f(tabPts[i].p_x,tabPts[i].p_y);
    }
    glEnd();

}

void MyPolygon::mouseAway(){

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    for(int i =0; i< N; i++){
        glVertex2f(tabPts[i].p_x,tabPts[i].p_y);

    }
    glEnd();

}
/**
 * the complexity of tringulation is O(N²) for time if not convexe
 * the complexity of triabgulation is O(N) for the time if convexe
 * and O(N) for the memory
 *
 */
void MyPolygon::triangulation(){
    vector<Vector2D *> tmp;
    for (int i = 0; i < N; ++i) {
       tmp.push_back(&(tabPts[i]));
    }

    int n=N;
    //while we can add a triangle to tabTriangles
    while (n>2){

        std::cout<< "while"<<std::endl;
        int i = 0;
        auto p = tmp.begin();
        bool test;
        //create a triangle using p,p+1,p+2 qs vertices
        Triangle T(*p,*(p+1),*(p+2));
        do{
            //
            std::cout<< "do"<<std::endl;

            test= !T.isEmpty(tmp,i+3);
            if(test){
                i++;
                p++;
                T=Triangle( *p, *(p + 1), *(p + 2));
            }
        }while(i<n-2 && test);

        assert(i<n-2);
//add triangle
        ptsTriangle.push_back(T);
        tmp.erase(p+1);
        n--;
        //or n = tmp.size();
    }
}
bool MyPolygon::isOnTheLeft(const Vector2D *P, const Vector2D *P1, const Vector2D *P2) {
    Vector2D AB = *P2-*P1;
    Vector2D AP = *P-*P2 ;
    return (AB.p_x*AP.p_y - AB.p_y* AP.p_x) >= 0 ;
}

