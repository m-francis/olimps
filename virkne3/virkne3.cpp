#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using std::cout;
using std::endl;

int main(){
    //Read input
    //std::ifstream infile("virkne3.in");
    char * virkne;
    std::ifstream is;
    is.open ("virkne3.in", std::ios::binary );

    // get length of file:
    is.seekg (0, std::ios::end);
    int len = is.tellg();
    is.seekg (0, std::ios::beg);

    // allocate memory:
    virkne = new char [len];

    // read data as a block:
    is.read (virkne,len);
    is.close();

    std::vector<char> final;
    for (int i = 0; i < len; ++i){
        char first = virkne[i];
        final.push_back(first);
        for (int j = i+1; j < len; ++j){
            if(first == virkne[j])
                continue;
            else{
                i = j - 1;
                break;
            }
        }
    }

    //cout << final << endl;

    //Write to output file
    std::ofstream outfile("virkne3.out");
    if(outfile.is_open()){
        for(int i = 0; i < final.size(); ++i){
            outfile << final[i];
        }
    } else return 0;

    return 0;
}
