/* 
 * File:   sahs1.cpp
 * Author: Martins Francis
 *
 * Created on 13 March 2012, 20:52
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

int main() {
    string pos;
    std::ifstream ifile("sahs1.dat");
    if (ifile.is_open()) {
        ifile >> pos;
    }

    int row = atoi( pos.substr(1,1).c_str() );
    int col;
    
    string scol = pos.substr(0,1);
    if(scol.compare("a") == 0) col = 1;
    else if(scol.compare("b") == 0) col = 2;
    else if(scol.compare("c") == 0) col = 3;
    else if(scol.compare("d") == 0) col = 4;
    else if(scol.compare("e") == 0) col = 5;
    else if(scol.compare("f") == 0) col = 6;
    else if(scol.compare("g") == 0) col = 7;
    else if(scol.compare("h") == 0) col = 8;

    cout << "row: " << row << " col: " << col << endl;

    std::ofstream ofile("sahs1.rez");
    if (ofile.is_open()) {
        for(int i = 8; i >= 1; --i){
            for(int j = 1; j <= 8; ++j){
                if(i == row && j == col)
                    ofile << 0;
                else if(i == row || j == col)
                    ofile << 1;
                else
                    ofile << 2;
            }
            ofile << endl;
        }
    }

    return 0;
}

