/* 
 * File:   sahs2.cpp
 * Author: Martins Francis
 *
 * Created on 13 March 2012, 21:09
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

bool uz_gaisa(int row, int col){
    if(col % 2 != 0 && row % 2 == 0 || col % 2 == 0 && row % 2 != 0){ //gaisie
        return true;
    } else{ // if(col % 2 != 0 && row % 2 != 0 || col % 2 == 0 && row % 2 == 0){ //tumsie
        return false;
    }
}

int main() {
    string pos;
    std::ifstream ifile("sahs2.dat");
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

    bool gaisie = uz_gaisa(row,col);

    std::ofstream ofile("sahs2.rez");
    if (ofile.is_open()) {
        for(int i = 8; i >= 1; --i){
            for(int j = 1; j <= 8; ++j){
                if(i == row && j == col){
                    ofile << 0;
                }else if(gaisie && uz_gaisa(i,j) || !gaisie && !uz_gaisa(i,j)){
                    //abi uz vienas krasas lauciniem
                    if( abs(i - row) == abs(j - col)){
                        ofile << 1;
                    } else{
                        ofile << 2;
                    }
                } else{
                    ofile << "*";
                }
            }
            ofile << endl;
        }
    }

    return 0;
}

