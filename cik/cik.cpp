#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

std::string convertInt(int number)
{
   std::stringstream ss;
   ss << number;
   return ss.str();
}

int main(){
    unsigned long num;
    int sk;

    std::ifstream ifile("cik.in");
    if ( ifile.is_open() )
    {
        string snum;
        getline(ifile,snum,' ');
        ifile >> sk;
        num = atoi( snum.c_str() );
        
        //cout << num << " : " << sk << endl;
    }

    int i = 0;
    bool flag = false;
    while(!flag){
        ++num;
        //cout << num << endl;
        ++i;
        string snum = convertInt(num);
        for(size_t i = 0; i != snum.size(); ++i){
            string digit = snum.substr(i,1);
            if( atoi(digit.c_str()) == sk ){
                flag = true;
                break;
            }
        }
    }

    cout << i << endl;

    std::ofstream ofile("cik.out");
    if(ofile.is_open())
    {
        ofile << i;
    }
    return 0;
}
