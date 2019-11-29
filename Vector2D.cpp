//
// Created by abou on 18/11/2019.
//

#include "Vector2D.h"

Vector2D::Vector2D(float pX, float pY) : p_x(pX), p_y(pY) {

}

Vector2D::Vector2D() {
    p_x=p_y=0;
}

Vector2D Vector2D::operator - (const Vector2D &op2) const {
    return Vector2D(p_x-op2.p_x,p_y-op2.p_y);
}

Vector2D Vector2D::operator + (const Vector2D &op2) const {
    return Vector2D(p_x+op2.p_x,p_y+op2.p_y);
}


Vector2D::Vector2D( const Vector2D &item ){
    p_x=item.p_x;
    p_y=item.p_y;
}

Vector2D::Vector2D(Vector2D *pD) {
        p_x = pD->p_x;
        p_y = pD->p_y;
};