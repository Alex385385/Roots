#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Roots.h"

using namespace std;

void readFile(string fileName, int &n, vector<float> &constt) {
    fstream myFile;
    myFile.open(fileName);
    if(!myFile) {
        cout << "Error Opening File" << endl;
    }

    myFile >> n;
    constt.resize(n + 1);

    for (int i = 0; i < n + 1; ++i) {
        myFile >> constt[i];
    }
}

void writeFile(vector<float> sol, int n, string fileName) {
    int size = fileName.size() - 4;
    string newFileName = fileName.substr(0,size);
    newFileName.append(".sol");

    ofstream outputFile(newFileName);
    for(int i = 0; i < n; i++) {
        outputFile << setprecision (32) << sol[i] << " ";
    }
}

int main(int argc, char* argv[]) {
    vector<float> ff = {1, 2, 10, -20};
    Roots rt;
    float y = rt.Newton(ff, 2, 10000, 3);


    cout << setprecision (32) << y << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
