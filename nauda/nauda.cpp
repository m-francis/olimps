#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cout;
using std::endl;

int main(){
    //Read input
    std::vector<int> data;
    std::ifstream file("nauda.in");
    std::copy(std::istream_iterator<int>(file), std::istream_iterator<int>(), std::back_inserter(data));

    int m = data[0];
    int s = data[1];
    int p = data[2];

    s = s + m * 20;
    p = p + s * 12;

    int jm = p / 100;
    int jp = p % 100;

    std::cout << jm << " " << jp << std::endl;

    //Write to output file
    std::ofstream outfile("nauda.out");
    if(outfile.is_open()){
        outfile << jm << " " << jp;
    } else return 0;

    return 0;
}
