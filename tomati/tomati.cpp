#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using std::cout;    using std::endl;
using std::string;

int main(){
    long n,s,d;
    std::ifstream ifile("tomati.dat");
    if(ifile.is_open()){
        string ns, ss, ds;
        getline(ifile,ns,' ');
        getline(ifile,ss,' ');
        getline(ifile,ds);
        n = atol( ns.c_str() );
        s = atol( ss.c_str() );
        d = atol( ds.c_str() );
    }

    long total = 1; //s

    //RHS
    if(s + d <= n){
        total += d;
    } else{
        total += n - s;
    }

    //LHS
    if(s - d >= 1){
        total += d;
    } else{
        total += s - 1;
    }

    cout << "TOT: " << total << endl;

    std::ofstream ofile("tomati.rez");
    if(ofile.is_open()){
        ofile << total;

    }
    
    return 0;
}
