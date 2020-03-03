//
// Created by Alejandro Millan on 3/2/20.
//

#ifndef ROOTS_ROOTS_H
#define ROOTS_ROOTS_H


class Roots {
public:
    Roots();

    virtual ~Roots();

    float Bisection(float f, float a, float b, int maxIter, float eps);

    float Newton(float f, float derF, float x, int maxIter, float eps, float delta);

    float Secant(float f, float a, float b, int maxIter, float eps);

};


#endif //ROOTS_ROOTS_H
