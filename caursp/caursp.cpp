/* 
 * File:   caursp.cpp
 * Author: Martins Francis
 *
 * Created on 10 March 2012, 20:29
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

std::string convertInt(int number)
{
   std::stringstream ss;
   ss << number;
   return ss.str();
}

int main() {
    string hr, min;
    std::ifstream ifile("caursp.dat");
    if (ifile.is_open()) {
        getline(ifile,hr,':');
        getline(ifile,min);

        cout << hr << endl;
        cout << min << endl;
    }

    int hr_i = atoi(hr.c_str());
    int min_i = atoi(min.c_str());

    int extra = 0;
    if(min_i != 0)
        extra = 1;

    int new_min = 60 - min_i;
    if(new_min == 60)
        new_min = 0;

    int new_hr = 12 - hr_i - extra;
    if(new_hr == 12)
        new_hr = 0;
    else if(new_hr < 0)
        new_hr = 11;

    string h = convertInt(new_hr);
    if(h.length() == 1){
        string z = "0";
        h = z.append(h);
    }

    string m = convertInt(new_min);
    if(m.length() == 1){
        string z = "0";
        m = z.append(m);
    }

    cout << h << ":" << m << endl;

    std::ofstream ofile("caursp.rez");
    if (ofile.is_open()) {
        ofile << h << ":" << m;
    }

    return 0;
}

