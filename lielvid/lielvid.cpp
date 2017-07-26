/* 
 * File:   lielvid.cpp
 * Author: Martins Francis
 *
 * Created on 10 March 2012, 21:21
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    int sum = 0;
    int skaits = 0;
    vector<int> skaitli;
    
    std::ifstream ifile("lielvid.dat");
    if (ifile.is_open()) {
        string sk_s;
        getline(ifile,sk_s);
        skaits = atoi(sk_s.c_str());

        string num;
        while(getline(ifile,num)){
            int sk = atoi(num.c_str());
            sum += sk;
            skaitli.push_back(sk);
        }
    }

    int vid = sum / skaits;

    cout << vid << endl;

    int lielaki = 0;
    for(int i = 0; i < skaitli.size(); ++i){
        if(skaitli[i] > vid)
            ++lielaki;
    }

    cout << lielaki << endl;

    std::ofstream ofile("lielvid.rez");
    if (ofile.is_open()) {
        ofile << lielaki;
    }

    return 0;
}

