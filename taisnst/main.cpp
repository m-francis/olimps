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
    std::ifstream file("taisnst.in");
    std::copy(std::istream_iterator<int>(file), std::istream_iterator<int>(), std::back_inserter(data));

    int n = data[0];
    int m = data[1];

    int final;
    while(true){
        if(n == 0 || m == 0){
            final += 0;
            break;
        } else if(n == m){
            final += 1;
            break;
        } else if(n == 1 || m == 1){
            final += n * m;
            break;
        } else if(n > m){
            int div = n / m;
            final += div;
            n -= div * m;
        } else if(m > n){
            int div = m / n;
            final += div;
            m -= div * n;
        }
    }

    cout << final << endl;

    //Write to output file
    std::ofstream outfile("taisnst.out");
    if(outfile.is_open()){
        outfile << final;
    } else return 0;

    return 0;
}
