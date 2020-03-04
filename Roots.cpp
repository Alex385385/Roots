//
// Created by Alejandro Millan on 3/2/20.
//

#include <iostream>
#include "Roots.h"
#include <cmath>

using namespace std;

Roots::Roots() {}

Roots::~Roots() {}


float Roots::Bisection(float f, float a, float b, int maxIter, float eps) {
    float fa;
    float fb;

    if((fa * fb) >= 0) {
        cout << "Inadequate values for a and b." << endl;
        return -1;
    }

    float error = b - a;
    for(int i = 0; i < maxIter; i++) {
        error = error / 2;
        float c = a + error;
        float fc;

        if(abs(error) < eps || fc == 0) {
            cout << "Algorithm has converged after #{it} iterations!" << endl;
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
    return 0;
}

/*
 * function Bisection(f : float -> float, a : float, b : float, maxIter : int, eps : float)
  fa := call f(a)
  fb := call f(b)

  if fa * fb >= 0 then
    print "Inadequate values for a and b."
    return -1.0
  end if

  error := b - a

  for it <- 1 to maxIter
    error := error / 2
    c := a + error
    fc := call f(c)

    if |error| < eps or fc = 0 then
      print "Algorithm has converged after #{it} iterations!"
      return c
    end if

    if fa * fc < 0 then
      b := c
      fb := fc
    else
      a := c
      fa := fc
    end if

  end for

  print "Max iterations reached without convergence..."
  return c
end function
 */

float Roots::Newton(float f, float derF, float x, int maxIter, float eps, float delta) {
    float fx;

    for(int i = 0; i < maxIter; i++) {
        float fd;

        if(abs(fd) < delta) {
            cout << "Small slope!" << endl;
            return x;
        }

        float d = fx/ fd;
        x = x - d;
        fx;

        if(abs(d) < eps) {
            cout << "Algorithm has converged after #{it} iterations!" << endl;
            return x;
        }
    }

    cout << "Max iterations reached without convergence..." << endl;
    return 0;
}

/*
 * function Newton(f : float -> float, derF : float -> float, x : float, maxIter : int, eps : float, delta : float)
  fx := call f(x)

  for it <- 1 to maxIter
    fd := call derF(x)

    if |fd| < delta then
      print "Small slope!"
      return x
    end if

    d := fx / fd
    x := x - d
    fx := call f(x)

    if |d| < eps then
      print "Algorithm has converged after #{it} iterations!"
      return x
    end if

  end for

  print "Max iterations reached without convergence..."
  return x
end function
 */

float Roots::Secant(float f, float a, float b, int maxIter, float eps) {
    float fa;
    float fb;

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
            cout << "Algorithm has converged after #{it} iterations!" << endl;
            return a;
        }

        a = a - d;
        fa;
    }

    cout << "Maximum number of iterations reached!" << endl;
    return a;
}

float Roots::f(float x, vector<float> equ) {
    float returnVal = 0;

    int arraySize = 3;
    for(int i = 0; i < arraySize; i++) {
        float temp = pow(x, arraySize - i);

        equ[i] = equ[i] * temp;
    }

    for(int i = 0; i < arraySize; i++) {
        returnVal += equ[i];
    }

    return 0;
}

float Roots::derF(std::vector<float> equ) {
    return 0;
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