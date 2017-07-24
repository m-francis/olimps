#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

int main(){
    //Read input
    std::ifstream infile("reiz.in");
    int i;
    if(infile.is_open()){
        infile >> i;
    } else return 1;

    //Do the exercise
    int mult = i * 2;
    
    cout << mult << endl;

    //Write to output file
    std::ofstream outfile("reiz.out");
    if(outfile.is_open()){
        outfile << mult;
    } else return 1;

    return 0;
}
