//
// Created by abou on 18/11/2019.
//

#ifndef RECTANGLES_VECTOR2D_H
#define RECTANGLES_VECTOR2D_H


class Vector2D {
public:
    Vector2D(float pX, float pY);
    Vector2D();

    Vector2D(Vector2D *pD);

    Vector2D operator -(const Vector2D &op2) const;

    Vector2D operator +(const Vector2D &op2) const;

    Vector2D( const Vector2D & );

    float p_x;
    float p_y;
};


#endif //RECTANGLES_VECTOR2D_H
