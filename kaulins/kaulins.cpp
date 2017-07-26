/* 
 * File:   kaulins.cpp
 * Author: Martins Francis
 *
 * Created on 13 March 2012, 16:31
 */

#include <iostream>
#include <fstream>
#include <string>
#include <set>
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
    int num, rolls;
    std::ifstream ifile("kaulins.dat");
    if (ifile.is_open()) {
        string s;
        getline(ifile,s,' ');
        num = atoi(s.c_str());
        getline(ifile,s);
        rolls = atoi(s.c_str());
    }

    int d[] = {1,2,3,4,5,6};
    std::set<int> dies (d,d+6);

    int mod = rolls % 4;

    string ret = "";
    switch(mod){
        case 0: ret = convertInt(num); break;
        case 2: ret = convertInt(7 - num); break;
        default:
            dies.erase(num);
            dies.erase(7 - num);
            std::set<int>::iterator it;
            for(it=dies.begin(); it != dies.end(); it++){
                int i = *it;
                string s = convertInt(i);
                ret.append( s );
            }
            break;
    }

    cout << ret << endl;

    std::ofstream ofile("kaulins.rez");
    if (ofile.is_open()) {
        ofile << ret;
    }

    return 0;
}

