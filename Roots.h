//
// Created by Alejandro Millan on 3/2/20.
//

#ifndef ROOTS_ROOTS_H
#define ROOTS_ROOTS_H

#include <vector>

class Roots {
private:
    float Newton(std::vector<float> f, std::vector<float> derF, float x, int maxIter, float eps, float delta, int n);

public:
    Roots();

    virtual ~Roots();

    float Bisection(std::vector<float> f, float a, float b, int maxIter, float eps, int n);

    float Newton(std::vector<float> f, float x, int maxIter, int n);

    float Secant(std::vector<float> f, float a, float b, int maxIter, float eps, int n);

    float func(float x, std::vector<float> equ, int arraySize);

    std::vector<float> derF(std::vector<float> equ, int n);

};


#endif //ROOTS_ROOTS_H
