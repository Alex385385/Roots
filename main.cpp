#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Roots.h"

using namespace std;

void readFile(string fileName, int &n, vector<float> &equ) {
    fstream myFile;
    myFile.open(fileName);
    if(!myFile) {
        cout << "Error Opening File" << endl;
    }

    myFile >> n;
    equ.resize(n + 1);

    for (int i = 0; i < n + 1; ++i) {
        myFile >> equ[i];
    }
}

void writeFile(string fileName, float rootAnswer, bool converge, int iter) {
    int size = fileName.size() - 4;
    string newFileName = fileName.substr(0,size);
    newFileName.append(".sol");

    ofstream outputFile(newFileName);

    outputFile << setprecision (32) << rootAnswer << " ";
    outputFile << iter << " ";
    if(converge) {
        outputFile << "success";
    } else {
        outputFile << "fail";
    }
}

int main(int argc, char* argv[]) {
    Roots rt;
    int n;
    int maxIter = 10000;
    vector<float> equation;
    string fileName;
    float initP1;
    float initP2;
    float z;
    bool conv = false;
    int iter = 0;

    if(string(argv[1]) == "-newt") {
        if(string(argv[2]) == "-maxIter") {
            maxIter = stoi(argv[3]);
            initP1 = stof(argv[4]);
            fileName = argv[5];

            readFile(fileName, n, equation);

            z = rt.Newton(equation, initP1, maxIter, n, conv, iter);

            writeFile(fileName, z, conv, iter);
        } else {
            initP1 = stof(argv[2]);
            fileName = argv[3];

            readFile(fileName, n, equation);

            z = rt.Newton(equation, initP1, maxIter, n, conv, iter);

            writeFile(fileName, z, conv, iter);
        }
    }
    else if(string(argv[1]) == "-sec") {
        if(string(argv[2]) == "-maxIter") {
            maxIter = stoi(argv[3]);
            initP1 = stof(argv[4]);
            initP2 = stof(argv[5]);
            fileName = argv[6];

            readFile(fileName, n, equation);

            z = rt.Secant(equation, initP1, initP2, maxIter, 0.0000001, n, conv, iter);

            writeFile(fileName, z, conv, iter);
        } else{
            initP1 = stof(argv[2]);
            initP2 = stof(argv[3]);
            fileName = argv[4];

            readFile(fileName, n, equation);

            z = rt.Secant(equation, initP1, initP2, maxIter, 0.0000001, n, conv, iter);

            writeFile(fileName, z, conv, iter);
        }
    } else if(string(argv[1]) == "-maxIter") {
        maxIter = stoi(argv[2]);
        initP1 = stof(argv[3]);
        initP2 = stof(argv[4]);
        fileName = argv[5];

        readFile(fileName, n, equation);

        z = rt.Bisection(equation, initP1, initP2, maxIter, 0.0000001, n, conv, iter);

        writeFile(fileName, z, conv, iter);
    } else {
        initP1 = stof(argv[1]);
        initP2 = stof(argv[2]);
        fileName = argv[3];

        readFile(fileName, n, equation);

        z = rt.Bisection(equation, initP1, initP2, maxIter, 0.0000001, n, conv, iter);

        writeFile(fileName, z, conv, iter);
    }

    return 0;
}
