#include <iostream>
#include <fstream>
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

/*
 * Add two strings consisting of natural numbers
 */
string add_two(string n1, string n2){
    n1 = std::string ( n1.rbegin(), n1.rend() ); //reverse string
    n2 = std::string ( n2.rbegin(), n2.rend() ); //reverse string

    string final;
    int carry = 0;
    for(size_t i = 0; i != n1.size(); ++i)
    {
        int i1 = atoi( n1.substr(i,1).c_str() );
        int i2 = atoi( n2.substr(i,1).c_str() );

        int sum = i1 + i2 + carry;

        int res = sum % 10;
        carry = sum / 10;

        final.append( convertInt(res) );
    }

    if(carry > 0)
        final.append( convertInt(carry) );

    final = std::string ( final.rbegin(), final.rend() ); //reverse string

    return final;
}

int main(){
    string num;
    std::ifstream ifile("summa2.in");
    if(ifile.is_open()){
        ifile >> num;
    }

    string sum = num;

    //cout << num << endl;
    
    while(num.size() >= 1){
        cout << num << endl;
        num = num.substr(1,num.size()-1);
        string n = num;
        while(n.size() < sum.size()){
            string m = "0";
            n = m.append(n);
        }
        sum = add_two(sum,n);
    }

    cout << sum << endl;

    std::ofstream ofile("summa2.out");
    if(ofile.is_open()){
        ofile << sum;
    }
    
    return 0;
}
