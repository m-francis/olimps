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
    std::ifstream file("skaitlis.in");
    std::copy(std::istream_iterator<int>(file), std::istream_iterator<int>(), std::back_inserter(data));

    int n = data[0];
    int m = data[1];

    while(true){
        n++;
        if(n % m == 0)
            break;
    }

    std::cout << n << std::endl;

    //Write to output file
    std::ofstream outfile("skaitlis.out");
    if(outfile.is_open()){
        outfile << n;
    } else return 0;

    return 0;
}
