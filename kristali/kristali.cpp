/* 
 * File:   kristali.cpp
 * Author: Martins Francis
 *
 * Created on 09 March 2012, 22:07
 */

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
    int kristali;
    std::ifstream ifile("kristali.dat");
    if (ifile.is_open()) {
        ifile >> kristali;
    }

    cout << kristali << endl;

    int minsum = 100, k, r, minr, mink;
    for(r = 1; r <= 10; ++r){
        int div = kristali / r;
        int mod = kristali % r;

        if(mod == 0)
            k = div;
        else
            k = div + 1;

        int sum = r + k;
        if(sum < minsum){
            minsum = sum;
            minr = r;
            mink = k;
        }
    }

    cout << "r: " << minr << endl;
    cout << "k: " << mink << endl;

    std::ofstream ofile("kristali.rez");
    if (ofile.is_open()) {
        ofile << minr << " " << mink;
    }

    return 0;
}

