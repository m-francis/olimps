/* 
 * File:   cipvirk3.cpp
 * Author: Martins Francis
 *
 * Created on 11 March 2012, 21:51
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
    int num;
    std::ifstream ifile("cipvirk3.dat");
    if (ifile.is_open()) {
        ifile >> num;
    }

    int sum = 0;
    for(int i=num; i >= 1; --i){
        string num_s = convertInt(i);
        string n = "1";
        while(n.length() < num_s.length()){
            n.append("0");
        }
        int ni = atoi(n.c_str());
        
        int diff = i - ni;
        int sk = num_s.length() * diff + num_s.length();
        sum += sk;

        i = ni;
    }

    cout << sum << endl;

    std::ofstream ofile("cipvirk3.rez");
    if (ofile.is_open()) {
        ofile << sum;
    }

    return 0;
}

