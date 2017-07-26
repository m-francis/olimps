/* 
 * File:   banka2.cpp
 * Author: Martins Francis
 *
 * Created on 13 March 2012, 19:53
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

int main() {
    int n,k,s;
    int darijumi;
    
    std::ifstream ifile("banka2.dat");
    if (ifile.is_open()) {
        string str;
        getline(ifile,str,' ');
        n = atoi(str.c_str());
        getline(ifile,str,' ');
        k = atoi(str.c_str());
        getline(ifile,str);
        s = atoi(str.c_str());

        getline(ifile,str);
        darijumi = atoi(str.c_str());

        //cout << n << " " << k << " " << s << endl;

        //cout << darijumi << endl;

        int no = n - k + 1;

        //cout << "NO: " << no << endl;

        int incount = 0;
        for(int i = 1; i <= darijumi; ++i){
            getline(ifile,str);
            bool sign = true; //positive
            if(str.substr(0,1).compare("-") == 0)
                sign = false; //negative
            int dar = atoi( str.c_str() );
            if(sign)
                ++incount;
            
            if(no == incount && sign){
                dar *= 2;
                incount = 0;
            }

            s += dar;

            //cout << dar << endl;
        }
    }

    cout << "FIN: " << s << endl;

    std::ofstream ofile("banka2.rez");
    if (ofile.is_open()) {
        ofile << s;
    }

    return 0;
}

