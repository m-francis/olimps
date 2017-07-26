/* 
 * File:   fragm.cpp
 * Author: Martins Francis
 *
 * Created on 13 March 2012, 10:36
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

int main() {
    std::vector<string> in;
    int total;
    
    std::ifstream ifile("fragm.dat");
    if (ifile.is_open()) {
        string e;
        getline(ifile,e);
        total = atoi(e.c_str());

        for(int i = 0; i < total; ++i){
            getline(ifile,e);
            e = e.substr(0,1);
            in.push_back(e);
        }
    }

    int longest = 0;

    //Iziet cauri visam sarakstam un atrod garako virkni
    for(int i = 0; i < total; ++i){
        string curr = in[i];
        int count = 1;
        int j = i+1;
        while(j < total && in[j].compare(curr) == 0){
            ++count;
            ++j;
        }
        i = j-1;
        if(count > longest)
            longest = count;
    }

    //Salidzina rindas prieksu un aizmuguri
    string first = in[0];
    string last = in[in.size()-1];
    if(longest != total && first.compare(last) == 0){
        int front = 1;
        int j = 1;
        while(j < total && in[j].compare(first) == 0){
            ++front;
            ++j;
        }

        int back = 1;
        j = in.size()-2;
        while(j >= 0 && in[j].compare(last) == 0){
            ++back;
            --j;
        }

        int tot = front + back;

        if(tot > longest)
            longest = tot;
    }

    cout << longest << endl;

    std::ofstream ofile("fragm.rez");
    if (ofile.is_open()) {
        ofile << longest;
    }

    return 0;
}

