#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using std::cout;
using std::endl;

int main(){
    //Read input
    std::ifstream infile("sumreiz.in");
    int inum;
    if(infile.is_open()){
        infile >> inum;
    } else return 0;

    int num = inum;
    for (int i = 0; i < inum; ++i){
        char c[30];
        sprintf(c,"%d",num);
        int sum = 0;
        int mul = 1;
        for(int j =0; j < strlen(c); ++j){
            int n = c[j] - '0';
            sum += n;
            mul *= n;
        }
        //cout << num << " + " << sum << " + " << mul << endl;
        num = num + sum + mul;
    }

    cout << num << endl;

    //Write to output file
    std::ofstream outfile("sumreiz.out");
    if(outfile.is_open()){
        outfile << num;
    } else return 0;

    return 0;
}
