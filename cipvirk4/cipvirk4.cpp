/* 
 * File:   cipvirk4.cpp
 * Author: Martins Francis
 *
 * Created on 11 March 2012, 22:43
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
    std::ifstream ifile("cipvirk4.dat");
    if (ifile.is_open()) {
        ifile >> num;
    }

    string cipari = "";
    string ns = convertInt(num);
    int pos;
    bool shortl = false;
    
    for(int i = 1; i <= num; ++i){
        cipari.append(convertInt(i));
        int find;
        if(shortl || cipari.length() >= 10){
            shortl = true;
            find = cipari.find(ns,cipari.length()-10);
        }else
            find = cipari.find(ns);
        
        if(find != -1){
            pos = find;
            break;
        }
    }

    cout << pos+1 << endl;

    std::ofstream ofile("cipvirk4.rez");
    if (ofile.is_open()) {
        ofile << pos+1;
    }

    return 0;
}

