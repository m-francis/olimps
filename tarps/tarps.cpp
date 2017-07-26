/* 
 * File:   tarps.cpp
 * Author: Martins Francis
 *
 * Created on 12 March 2012, 10:59
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

int main() {
    int row = 0;
    int col = 0;
    
    std::ifstream ifile("tarps.dat");
    if (ifile.is_open()) {
        string r,c;
        getline(ifile,r,' ');
        getline(ifile,c);
        row = atoi(r.c_str());
        col = atoi(c.c_str());
    }

    int count = 0;
    while(true){
        if(row > 0){
            row -= 1;
            ++count;
        }
        
        if(row == 0 || col == 0)
            break;

        if(col > 0){
            col -= 1;
            ++count;
        }
        
        if(row == 0 || col == 0)
            break;
    }

    cout << count-1 << endl;

    std::ofstream ofile("tarps.rez");
    if (ofile.is_open()) {
        ofile << count-1;
    }

    return 0;
}

