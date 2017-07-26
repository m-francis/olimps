/* 
 * File:   sahs4.cpp
 * Author: Martins Francis
 *
 * Created on 14 March 2012, 20:55
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
    std::ifstream ifile("sahs4.dat");
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

    std::ofstream ofile("sahs4.rez");
    if (ofile.is_open()) {
        for(int i = 8; i >= 1; --i){
            for(int j = 1; j <= 8; ++j){
                if(i == row && j == col)
                    ofile << 0;
                else if(i == row){
                    ofile << abs(j-col);
                } else if(j == col){
                    ofile << abs(i-row);
                } else if(abs(i - row) == abs(j - col)){
                    ofile << abs(i - row);
                } else{
                    int r = i;
                    int c = j;
                    bool incrow, inccol;
                    
                    if(r > row) incrow = false;
                    else incrow = true;
                    if(c > col) inccol = false;
                    else inccol = true;

                    int count = 0;
                    while(true){
                        if(incrow)
                            ++r;
                        else
                            --r;
                        
                        if(inccol)
                            ++c;
                        else
                            --c;

                        count += 1;

                        if(r==row){
                            count += abs(c-col);
                            break;
                        }else if(c==col){
                            count += abs(r-row);
                            break;
                        }
                    }
                    
                    ofile << count;
                }
            }
            ofile << endl;
        }
    }

    return 0;
}

