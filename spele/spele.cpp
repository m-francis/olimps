/* 
 * File:   spele.cpp
 * Author: Martins Francis
 *
 * Created on 13 March 2012, 17:05
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

int main() {
    int pirmais = 0;
    int otrais = 0;
    int tresais = 0;
    
    std::ifstream ifile("spele.dat");
    if (ifile.is_open()) {
        string s;
        getline(ifile,s);
        int count = atoi(s.c_str());

        for(int i = 0; i < count; ++i){
            int p,o,t;
            getline(ifile,s,' ');
            p = atoi(s.c_str());
            getline(ifile,s,' ');
            o = atoi(s.c_str());
            getline(ifile,s);
            t = atoi(s.c_str());

            // 1) visi atskirigi
            if(p != o && o != t && p != t){
                if(p>o && p>t)
                    ++pirmais;
                else if(o>p && o>t)
                    ++otrais;
                else
                    ++tresais;
            }
            // 2) divi vienadi, tresais atskirigs
            else if(p == o && p != t)
                ++tresais;
            else if(p == t && p != o)
                ++otrais;
            else if(o == p && o != t)
                ++tresais;
            else if(o == t && o != p)
                ++pirmais;
            else if(t == p && t != o)
                ++otrais;
            else if(t == o && t != p)
                ++pirmais;
        }
    }

    cout << pirmais << " " << otrais << " " << tresais << endl;

    std::ofstream ofile("spele.rez");
    if (ofile.is_open()) {
        ofile << pirmais << " " << otrais << " " << tresais;
    }

    return 0;
}

