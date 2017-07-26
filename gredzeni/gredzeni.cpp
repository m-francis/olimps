/* 
 * File:   gredzeni.cpp
 * Author: Martins Francis
 *
 * Created on 12 March 2012, 23:49
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

int main() {
    int out_d, in1_d, out1_d, in2_d, out2_d;
    std::ifstream ifile("gredzeni.dat");
    if (ifile.is_open()) {
        string s;
        getline(ifile,s);
        out_d = atoi(s.c_str());
        getline(ifile,s,' ');
        in1_d = atoi(s.c_str());
        getline(ifile,s);
        out1_d = atoi(s.c_str());
        getline(ifile,s,' ');
        in2_d = atoi(s.c_str());
        getline(ifile,s);
        out2_d = atoi(s.c_str());
    }

    cout << out_d << endl;
    cout << in1_d << " " << out1_d << endl;
    cout << in2_d << " " << out2_d << endl;

    string abus = "ABUS";
    string vienu = "VIENU";
    string pirmo = "PIRMO";
    string otro = "OTRO";
    string nev = "NEVIENU";

    string ret = "";

    if(out1_d <= out_d || out2_d <= out_d){
        if(out1_d <= out_d && in1_d >= out2_d || out2_d <= out_d && in2_d >= out1_d || out1_d + out2_d <= out_d){
            ret = abus;
        } else if(out1_d <= out_d && out2_d <= out_d){
            ret = vienu;
        } else if(out1_d <= out_d){
            ret = pirmo;
        } else if(out2_d <= out_d){
            ret = otro;
        }
    } else{
        ret = nev;
    }

    cout << ret << endl;

    std::ofstream ofile("gredzeni.rez");
    if (ofile.is_open()) {
        ofile << ret;
    }

    return 0;
}

