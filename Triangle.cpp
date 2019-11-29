//
// Created by abou on 25/11/2019.
//

#include <vector>
#include "Triangle.h"

Triangle::Triangle(Vector2D *ptr1, Vector2D *ptr2,Vector2D *ptr3){

    ptr[0] = ptr1;
    ptr[1] = ptr2;
    ptr[2] = ptr3;

}

bool Triangle::isInside(Vector2D *p) {

return isOnTheLeft(p,ptr[0],ptr[1]) && isOnTheLeft(p,ptr[1],ptr[2]) && isOnTheLeft(p,ptr[2],ptr[0]);


}

bool Triangle::isOnTheLeft(Vector2D *P, Vector2D *P1, Vector2D *P2) {

Vector2D AB = *P2-*P1;
Vector2D AP = *P-*P2 ;

return (AB.p_x*AP.p_y - AB.p_y* AP.p_x) >= 0 ;
}

bool Triangle::isEmpty(const std::vector<Vector2D*> &tmp, int n){
    auto p= tmp.begin()+ n;
    while(p!=tmp.end() && !isInside(*p)){
        p++;
    }
    return (p==tmp.end());
}