#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <string>
#include <set>

using std::cout;
using std::endl;

int main(){
    std::set<std::string> unique;
    
    std::ifstream myfile ("lacisi.in");
    if (myfile.is_open())
    {
        std::string line1;
        getline (myfile,line1);
        int lc = atoi(line1.c_str());
        for(int i = 0; i != lc; ++i){
            std::string line2;
            getline (myfile,line2);
            std::string num = line2.substr(37,4);
            //cout << line2 << endl;
            //cout << num << endl;
            unique.insert(num);
        }

        myfile.close();
    }

    //cout << unique.size() << endl;

    //Write to output file
    std::ofstream outfile("lacisi.out");
    if(outfile.is_open()){
        outfile << unique.size();
    } else return 0;

    return 0;
}
