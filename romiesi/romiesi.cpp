/* 
 * File:   romiesi.cpp
 * Author: Martins Francis
 *
 * Created on 12 March 2012, 21:44
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::string;

int main() {
    string virkne;
    std::ifstream ifile("romiesi.dat");
    if (ifile.is_open()) {
        ifile >> virkne;
    }

    std::map<string,int> romiesi;
    romiesi["I"] = 1;
    romiesi["V"] = 5;
    romiesi["X"] = 10;
    romiesi["L"] = 50;
    romiesi["C"] = 100;
    romiesi["D"] = 500;
    romiesi["M"] = 1000;

    int sum = 0;
    for(size_t i = 0; i < virkne.length(); ++i){
        string curr = virkne.substr(i,1);
        int curr_int = romiesi.find(curr)->second;

        bool sign = true; //+
        if(i + 1 != virkne.length()){
            string next = virkne.substr(i+1,1);
            int next_int = romiesi.find(next)->second;
            //cout << " comparing " << curr_int << " < " << next_int << endl;
            if(curr_int < next_int)
                sign = false; //-
        }

        int sk = romiesi.find(curr)->second;

        if(sign){
            //cout << "+" << sk;
            sum += sk;
        }else{
            //cout << "-" << sk;
            sum -= sk;
        }
    }

    cout << " = " << sum << endl;

    std::ofstream ofile("romiesi.rez");
    if (ofile.is_open()) {
        ofile << sum;
    }

    return 0;
}

