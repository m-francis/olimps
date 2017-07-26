#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using std::cout;    using std::endl;
using std::string;

int main(){
    long n;
    int k,m;
    std::ifstream ifile("konfdal.dat");
    if(ifile.is_open()){
        string ns, ks, ms;
        getline(ifile,ns,' ');
        getline(ifile,ks,' ');
        getline(ifile,ms);
        n = atol( ns.c_str() );
        k = atoi( ks.c_str() );
        m = atoi( ms.c_str() );
    }

    int sum = k + m;
    int total = (n / sum ) * 2;

    int diff = n % sum;

    bool k_is = true;
    while(diff > 0){
        if(k_is){
            total++;
            k_is = false;
            diff -= k;
        } else{
            total++;
            k_is = true;
            diff -= m;
        }
    }

    cout << total << endl;

    std::ofstream ofile("konfdal.rez");
    if(ofile.is_open()){
        ofile << total;
    }

    return 0;
}
