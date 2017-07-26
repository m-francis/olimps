/* 
 * File:   sahs9.cpp
 * Author: Martins Francis
 *
 * Created on 15 March 2012, 09:17
 */

#include <iostream>
#include <fstream>
#include <string>
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

bool inbetween(int sr, int sc, int tr, int tc, int zr, int zc){
    while(true){
        if(sr == tr && sc == tc){
            return false;
        } else if(sr == zr && sc == zc ){
                return true;
        } else if(abs(sr-tr) != abs(sc-tc) && sr != tr && sc != tc){
            return false;
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
    std::ifstream ifile("sahs9.dat");
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

    std::ofstream ofile("sahs9.rez");
    if (ofile.is_open()) {
        for(int i = 8; i >= 1; --i){
            for(int j = 1; j <= 8; ++j){
                if(i == darow && j == dacol){
                    ofile << 0;
                    cout << 0;
                } else if(i == skrow && j == skcol){
                    ofile << "*";
                    cout << "*";
                } else{
                    bool add = false;
                    int ret;
                    if(i == darow){
                        ret = abs(j-dacol);
                    } else if(j == dacol){
                        ret = abs(i-darow);
                    } else if(abs(i - darow) == abs(j - dacol)){
                        ret = abs(i - darow);
                        add = true;
                    } else{
                        int r = i;
                        int c = j;
                        bool incrow, inccol;

                        if(r > darow) incrow = false;
                        else incrow = true;
                        if(c > dacol) inccol = false;
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

                            if(r==darow){
                                count += abs(c-dacol);
                                break;
                            }else if(c==dacol){
                                count += abs(r-darow);
                                break;
                            }
                        }

                        ret = count;
                    }

                    if(!inbetween(i,j,darow,dacol,skrow,skcol)){
                        ofile << ret;
                        cout << ret;
                    } else{
                        if(add){
                            ofile << ret + 1;
                            cout << ret + 1;
                        } else{
                            ofile << ret;
                            cout << ret;
                        }
                    }
                }
            }
            ofile << endl;
            cout << endl;
        }
    }

    return 0;
}

