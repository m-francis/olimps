/* 
 * File:   perskods.cpp
 * Author: Martins Francis
 *
 * Created on 10 March 2012, 22:08
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

int main() {
    string num;
    std::ifstream ifile("perskods.dat");
    if (ifile.is_open()) {
        ifile >> num;
    }

    int one = 2 * atoi(num.substr(0,1).c_str());
    int two = 7 * atoi(num.substr(1,1).c_str());
    int thr = 6 * atoi(num.substr(2,1).c_str());
    int fou = 5 * atoi(num.substr(3,1).c_str());
    int fiv = 4 * atoi(num.substr(4,1).c_str());
    int six = 3 * atoi(num.substr(5,1).c_str());
    int sev = 2 * atoi(num.substr(6,1).c_str());

    int sum = one + two + thr + fou + fiv + six + sev;

    int mod = sum % 11;

    string let;
    switch(mod){
        case 0: let = "J"; break;
        case 1: let = "A"; break;
        case 2: let = "B"; break;
        case 3: let = "C"; break;
        case 4: let = "D"; break;
        case 5: let = "E"; break;
        case 6: let = "F"; break;
        case 7: let = "G"; break;
        case 8: let = "H"; break;
        case 9: let = "I"; break;
        case 10: let = "Z"; break;
    }

    cout << num << let << endl;

    std::ofstream ofile("perskods.rez");
    if (ofile.is_open()) {
        ofile << let;
    }

    return 0;
}

