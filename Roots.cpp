//
// Created by Alejandro Millan on 3/2/20.
//

#include <iostream>
#include "Roots.h"
#include <cmath>

using namespace std;

Roots::Roots() {}

Roots::~Roots() {}


float Roots::Bisection(vector<float> f, float a, float b, int maxIter, float eps, int n, bool &conv, int &iter) {
    float fa = func(a, f, n);
    float fb = func(b, f, n);
    float c = 0.0;

    if((fa * fb) >= 0) {
        cout << "Inadequate values for a and b." << endl;
        conv = false;
        iter = 0;
        return -1;
    }

    float error = b - a;
    for(int i = 0; i < maxIter; i++) {
        error = error / 2;
        c = a + error;
        float fc = func(c, f, n);

        if(abs(error) < eps || fc == 0) {
            cout << "Algorithm has converged after " << i + 1 << " iterations!" << endl;
            conv = true;
            iter = i + 1;
            return c;
        }

        if((fa * fc) < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    cout << "Max iterations reached without convergence..." << endl;
    conv = false;
    iter = maxIter;
    return c;
}

float Roots::Newton(vector<float> f, float x, int maxIter, int n, bool &conv, int &iter) {
    vector<float> der(derF(f, n));

    return Newton(f, der, x, maxIter, 0.0000001, 0.00000000000001, n + 1, conv, iter);
}

float Roots::Newton(vector<float> f, vector<float> derF, float x, int maxIter, float eps, float delta, int n, bool &conv, int &iter ) {
    float fx = func(x, f, n);

    for(int i = 0; i < maxIter; i++) {
        float fd = func(x, derF, n - 1);

        if(abs(fd) < delta) {
            cout << "Small slope!" << endl;
            conv = false;
            iter = i + 1 + iter;
            return x;
        }

        float d = fx/ fd;
        x = x - d;
        fx = func(x, f, n);

        if(abs(d) < eps) {
            cout << "Algorithm has converged after " << i + 1 << " iterations!" << endl;
            conv = true;
            iter = i + 1 + iter;
            return x;
        }
    }

    cout << "Max iterations reached without convergence..." << endl;
    conv = false;
    iter = maxIter;
    return x;
}

float Roots::Secant(vector<float> f, float a, float b, int maxIter, float eps, int n, bool &conv, int &iter) {
    float fa = func(a, f, n);
    float fb = func(b, f, n);

    if(abs(fa) > abs(fb)) {
        swap(a,b);
        swap(fa, fb);
    }

    for(int i = 0; i < maxIter; i++) {
        if(abs(fa) > abs(fb)) {
            swap(a,b);
            swap(fa, fb);
        }

        float d = (b - a) / (fb - fa);
        b = a;
        fb = fa;
        d = d * fa;

        if(abs(d) < eps) {
            cout << "Algorithm has converged after " << i + 1 << " iterations!" << endl;
            conv = true;
            iter = i + 1;
            return a;
        }

        a = a - d;
        fa = func(a, f, n);
    }

    cout << "Maximum number of iterations reached!" << endl;
    conv = false;
    iter = maxIter;
    return a;
}

float Roots::func(float x, vector<float> equ, int arraySize) {
    float returnVal = 0;

    for(int i = 0; i < arraySize; i++) {
        float temp = pow(x, arraySize - i);

        equ[i] = equ[i] * temp;
    }

    for(int i = 0; i < arraySize; i++) {
        returnVal += equ[i];
    }

    return returnVal;
}

vector<float> Roots::derF(std::vector<float> equ, int n) {
    vector<float> newVector(n);

    for(int i = 0; i < n; i++) {
        newVector[i] = equ[i] * ((float)(n - i));
    }

    return newVector;
}

float Roots::Hybrid(std::vector<float> f, float a, float b, int maxIter, float eps, int n, bool &conv, int &iter) {
    float x = Bisection(f, a, b, 10, eps, n, conv, iter);

    return Newton(f, x, maxIter - 10, n, conv, iter+=10);
}
