/* 
 * File:   rendzju.cpp
 * Author: Martins Francis
 *
 * Created on 10 March 2012, 22:27
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;
using std::vector;

std::string convertInt(int number)
{
   std::stringstream ss;
   ss << number;
   return ss.str();
}

bool match_seq(string line, string match_seq, int m){
    bool match = false;
    int found = int(line.find(match_seq));
    
    if( found != -1 ){
        bool after = true;
        if(found != line.length() - 5){
            if( atoi(line.substr(found + 5, 1).c_str()) == m)
                after = false;
        }

        if(after) match = true;
    }

    return match;
}

/*
 * Returns 0 1 2 depending on whether something could be matched.
 */
int match(string line){
    if(match_seq(line,"11111",1))
        return 1;
    else if(match_seq(line,"22222",2))
        return 2;
    else
        return 0;
}

int main() {
    vector< vector<int> > laukums(19, vector<int>(19));
    
    std::ifstream ifile("rendzju.dat");
    if (ifile.is_open()) {
        for(int i = 0; i < 19; ++i){
            for(int j = 0; j < 19; ++j){
                string n;
                if(j < 18)
                    getline(ifile,n,' ');
                else
                    getline(ifile,n);
                laukums[i][j] = atoi(n.c_str());
            }
        }
    }

    int won = 0;

    /* HORIZONTALI un VERTIKALI */
    for(int i = 0; i < 19; ++i){
        string hor_line = "";
        string ver_line = "";
        for(int j = 0; j < 19; ++j){
            hor_line.append( convertInt(laukums[i][j]) );
            ver_line.append( convertInt(laukums[j][i]) );
        }

        //mekle horizontali
        int mh = match(hor_line);
        if(mh > 0){
            won = mh;
            break;
        }

        //mekle vertikali
        int mv = match(ver_line);
        if(mv > 0){
            won = mv;
            break;
        }
    }

    /* DIAGONALI 1 */
    if(won == 0){
        //no kreisas augsas lidz labajai apaksai
        for(int i = 0; i < 19; ++i){
            string di1_line = "";
            int d1row = i;
            for(int j = 0; j < 19; ++j){
                if(d1row >= 0){
                    di1_line.append( convertInt(laukums[d1row][j]) );
                    --d1row;
                }
            }

            int d1 = match(di1_line);
            if(d1 > 0){
                won = d1;
                break;
            }

            //cout << di1_line << endl;

            string di2_line = "";
            int d2row = 18;
            for(int j = i; j < 19; ++j){
                di2_line.append( convertInt(laukums[d2row][j]) );
                --d2row;
            }

            int d2 = match(di2_line);
            if(d2 > 0){
                won = d2;
                break;
            }

            //cout << di2_line << endl;
        }
    }

    /* DIAGONALI 2 */
    if(won == 0){
        //no labas augsas lidz kreisajai apaksai
        for(int i = 0; i < 19; ++i){
            string di1_line = "";
            int d1row = 0;
            for(int j = i; j < 19; ++j){
                di1_line.append( convertInt(laukums[d1row][j]) );
                ++d1row;
            }

            int d1 = match(di1_line);
            if(d1 > 0){
                won = d1;
                break;
            }

            //cout << di1_line << endl;

            string di2_line = "";
            int d2row = i+1;
            for(int j = 0; j < 19; ++j){
                if(d2row < 19){
                    di2_line.append( convertInt(laukums[d2row][j]) );
                    ++d2row;
                }
            }

            int d2 = match(di2_line);
            if(d2 > 0){
                won = d2;
                break;
            }

            //cout << di2_line << endl;
        }
    }

    cout << "WON: " << won << endl;

    std::ofstream ofile("rendzju.rez");
    if (ofile.is_open()) {
        ofile << won;
    }

    return 0;
}

