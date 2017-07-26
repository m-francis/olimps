/* 
 * File:   sahs8.cpp
 * Author: Martins Francis
 *
 * Created on 14 March 2012, 22:18
 */

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

//row,col
std::pair<int,int> get_position(string pos){
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

    std::pair<int,int> coord = std::make_pair(row,col);

    return coord;
}

bool uz_gaisa(int row, int col){
    if(col % 2 != 0 && row % 2 == 0 || col % 2 == 0 && row % 2 != 0){ //gaisie
        return true;
    } else{ // if(col % 2 != 0 && row % 2 != 0 || col % 2 == 0 && row % 2 == 0){ //tumsie
        return false;
    }
}

bool inbetween(int sr, int sc, int tr, int tc, int zr, int zc){
    while(true){
        if(sr == tr && sc == tc){
            return false;
        } else if(sr == zr && sc == zc ){
            return true;
        } else{
            if(sr != tr){
                if(sr < tr) ++sr;
                else --sr;
            }
            if(sc != tc){
                if(sc < tc) ++sc;
                else --sc;
            }
        }
    }
}

int main() {
    string pos, skerslis;
    std::ifstream ifile("sahs8.dat");
    if (ifile.is_open()) {
        getline(ifile,pos);
        getline(ifile,skerslis);
    }

    std::pair<int,int> source_coord = get_position(pos);
    int darow = source_coord.first;
    int dacol = source_coord.second;
    std::pair<int,int> sk_coord = get_position(skerslis);
    int skrow = sk_coord.first;
    int skcol = sk_coord.second;

    bool gaisie = uz_gaisa(darow,dacol);

    std::ofstream ofile("sahs8.rez");
    if (ofile.is_open()) {
        for(int r = 8; r >= 1; --r){
            for(int c = 1; c <= 8; ++c){
                if(r == darow && c == dacol){
                    ofile << 0;
                    cout << 0;
                }else if(r == skrow && c == skcol){
                    ofile << "*";
                    cout << "*";
                }else if(!inbetween(r,c,darow,dacol,skrow,skcol)){
                    if(r == darow || c == dacol){
                        ofile << 1;
                        cout << 1;
                    }else if(gaisie && uz_gaisa(r,c) || !gaisie && !uz_gaisa(r,c)){
                        //abi uz vienas krasas lauciniem
                        if( abs(r - darow) == abs(c - dacol)){
                            ofile << 1;
                            cout << 1;
                        } else{
                            ofile << 2;
                            cout << 2;
                        }
                    } else{
                        ofile << 2;
                        cout << 2;
                    }
                } else{
                    if(r == darow || c == dacol){
                        if(r >= dacol || c >= darow){
                            ofile << 2;
                            cout << 2;
                        } else{
                            ofile << 3;
                            cout << 3;
                        }
                    } else{
                        ofile << 2;
                        cout << 2;
                    }
                }
            }
            ofile << endl;
            cout << endl;
        }
    }

    return 0;
}

