//
// Created by Alejandro Millan on 3/2/20.
//

#ifndef ROOTS_ROOTS_H
#define ROOTS_ROOTS_H

#include <vector>

class Roots {
public:
    Roots();

    virtual ~Roots();

    float Bisection(float f, float a, float b, int maxIter, float eps);

    float Newton(float f, float derF, float x, int maxIter, float eps, float delta);

    float Secant(float f, float a, float b, int maxIter, float eps);

    float f(float x, std::vector<float> equ);

    float derF(std::vector<float> equ)

};


#endif //ROOTS_ROOTS_H
