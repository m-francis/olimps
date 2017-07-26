#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cout;    using std::endl;
using std::string;  using std::vector;

int main(){
    long ret;
    
    std::ifstream ifile("vidsk.dat");    
    if(ifile.is_open()){
        string in_num;
        getline(ifile,in_num);
        int length = atoi( in_num.c_str() );

        long in[length];
        long count = 0;
        while(getline(ifile,in_num)){
            in[count] = atol( in_num.c_str() );
            ++count;
        }

        std::sort(in,in + length);

        int i = length / 2;
        
        cout << in[i] << endl;

        ret = in[i];
    }

    std::ofstream ofile("vidsk.rez");
    if(ofile.is_open()){
        ofile << ret;
    }
    
    return 0;
}
