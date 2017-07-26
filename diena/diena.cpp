#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

int main(int argc, char** argv) {
    //Read input
    std::ifstream infile("diena.in");
    int inum;
    if(infile.is_open()){
        infile >> inum;
    } else return 0;

    //std::vector<int> months;
    int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int curr = months[0];
    int count = 1;
    while(inum > curr){
        inum -= curr;
        curr = months[count];
        ++count;
    }
    //std::cout << "day: " << inum << " mon: " << count << std::endl;
    std::ofstream outfile("diena.out");
    if(outfile.is_open()){
        outfile << inum << " " << count;
    } else return 0;

    return 0;
}

