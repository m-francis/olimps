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
    std::string line1;
    std::string line2;
    std::ifstream myfile ("burti.in");
    if (myfile.is_open())
    {
        getline (myfile,line1);
        getline (myfile,line2);
        //cout << line1 << endl;
        //cout << line2 << endl;

        myfile.close();
    }

    std::string result = "VAR";

    for(int i = 0; i < line2.size(); ++i){
        for(int j = 0; j < line1.size(); ++j){
            if(line1[j] == line2[i]){
                line1[j] = '0';
                line2[i] = '0';
                break;
            }
        }
    }

    //cout << line2 << " " << line1 << endl;

    for(int i = 0; i < line2.size(); ++i){
        if(line2[i] == '0')
            continue;
        else{
            result = "NEVAR";
            break;
        }
    }

    //cout << result << endl;

    //Write to output file
    std::ofstream outfile("burti.out");
    if(outfile.is_open()){
        outfile << result;
    } else return 0;

    return 0;
}
