#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void readFile(string fileName, int &n, vector<vector<float>> &coeff, vector<float> &constt) {
    fstream myFile;
    myFile.open(fileName);
    if(!myFile) {
        cout << "Error Opening File" << endl;
    }

    myFile >> n;
    coeff.resize(n, vector<float>(n));
    constt.resize(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            myFile >> coeff[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
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
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
