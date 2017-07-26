#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using std::cout; using std::endl; using std::string;

std::string convertInt(int number)
{
   std::stringstream ss;
   ss << number;
   return ss.str();
}

int main(){
    string num;
    std::ifstream ifile("mazsk.in");
    if(ifile.is_open()){
        ifile >> num;
    }

    int n[num.size()];
    for(size_t i = 0; i < num.size(); ++i){
        n[i] = atoi( num.substr(i,1).c_str() );
    }
    std::vector<int> v(n, n + sizeof(n) / sizeof(int));

    std::sort(v.begin(), v.end());

    std::ofstream ofile("mazsk.out");
    if(ofile.is_open()){
        int i;
        string in;
        for(i = 0; i < v.size(); ++i){
            if(v[i] != 0)
                break;
            else
                in = in.append( convertInt(v[i]) );
        }

        ofile << v[i];
        cout << v[i];
        ofile << in;
        cout << in;
        
        for(int j = i+1; j < v.size(); ++j){
            ofile << v[j];
            cout << v[j];
        }
    }
    return 0;
}
