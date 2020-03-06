//
// Created by Alejandro Millan on 3/2/20.
//

#include <iostream>
#include "Roots.h"
#include <cmath>

//#define eps = 0.00000001;

using namespace std;

Roots::Roots() {}

Roots::~Roots() {}


float Roots::Bisection(vector<float> f, float a, float b, int maxIter, float eps, int n) {
    float fa = func(a, f, n);
    float fb = func(b, f, n);
    float c = 0.0;

    if((fa * fb) >= 0) {
        cout << "Inadequate values for a and b." << endl;
        return -1;
    }

    float error = b - a;
    for(int i = 0; i < maxIter; i++) {
        error = error / 2;
        c = a + error;
        float fc = func(c, f, n);

        if(abs(error) < eps || fc == 0) {
            cout << "Algorithm has converged after " << i << " iterations!" << endl;
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
    return c;
}

float Roots::Newton(vector<float> f, float x, int maxIter, int n) {
    vector<float> der(derF(f, n));

    return Newton(f, der, x, maxIter, 0.000000001, 0.00000000000001, n + 1);
}

float Roots::Newton(vector<float> f, vector<float> derF, float x, int maxIter, float eps, float delta, int n) {
    float fx = func(x, f, n);

    for(int i = 0; i < maxIter; i++) {
        float fd = func(x, derF, n - 1);

        if(abs(fd) < delta) {
            cout << "Small slope!" << endl;
            return x;
        }

        float d = fx/ fd;
        x = x - d;
        fx = func(x, f, n);

        if(abs(d) < eps) {
            cout << "Algorithm has converged after " << i << " iterations!" << endl;
            return x;
        }
    }

    cout << "Max iterations reached without convergence..." << endl;
    return x;
}

float Roots::Secant(vector<float> f, float a, float b, int maxIter, float eps, int n) {
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
            cout << "Algorithm has converged after " << i << " iterations!" << endl;
            return a;
        }

        a = a - d;
        fa = func(a, f, n);
    }

    cout << "Maximum number of iterations reached!" << endl;
    return a;
}

/*
 * function Secant(f : float -> float, a : float, b : float, maxIter : int, eps : float)
  fa := call f(a)
  fb := call f(b)

  if |fa| > |fb| then
    swap(a, b)
    swap(fa, fb)
  end if

  for it <- 1 to maxIter
    if |fa| > |fb| then
      swap(a, b)
      swap(fa, fb)
    end if

    d := (b - a) / (fb - fa)
    b := a
    fb := fa
    d := d * fa

    if |d| < eps then
      print "Algorithm has converged after #{it} iterations!"
      return a
    end if

    a := a - d
    fa := call f(a)
  end for

    print "Maximum number of iterations reached!"
    return a
end function
 */

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