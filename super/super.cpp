#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

/*
 * Multiply two strings consisting of natural numbers
 */
string mul_two(string n1, string n2){
    std::vector<string> muls;
    //cout << "MUL TWO: " << n1 << " : " << n2 << endl;

    n1 = std::string ( n1.rbegin(), n1.rend() ); //reverse string
    n2 = std::string ( n2.rbegin(), n2.rend() ); //reverse string

    for(size_t i = 0; i != n2.size(); ++i)
    {
        //cout << "ROUND: " << i << endl;
        string mul;
        int carry = 0;
        int dg2 = atoi( n2.substr(i,1).c_str() );
        //cout << "  dg2: " << dg2 << endl;

        for(size_t j = 0; j != n1.size(); ++j)
        {
            int dg1 = atoi( n1.substr(j,1).c_str() );
            //cout << "  dg1: " << dg1 << endl;
            int m = dg1 * dg2 + carry;
            carry = m / 10;
            int f = m % 10;
            string fs = convertInt(f);
            mul.append(fs);
        }

        if(carry > 0)
            mul.append( convertInt(carry) );

        mul = std::string ( mul.rbegin(), mul.rend() ); //reverse string

        //cout << "  MUL: " << mul << endl;
        
        muls.push_back(mul);
    }

    //Get the size of the longest string
    size_t longest = 0;
    for(size_t i = 0; i != muls.size(); ++i)
    {
        size_t j = 0;
        while(j != i)
        {
            ++j;
            muls[i] = muls[i].append("0");
        }
        if(longest < muls[i].size())
            longest = muls[i].size();
    }
    //cout << "long " << longest << endl;

    //Surround all strings with zeros so they are all the same length
    for(size_t i = 0; i != muls.size(); ++i)
    {
        if(muls[i].size() < longest)
        {
            string temp;
            while(temp.size() + muls[i].size() < longest)
                temp.append("0");
            
            temp.append(muls[i]);
            muls[i] = temp;
        }
    }
    string res = muls[0];
    
    for(size_t i = 1; i != muls.size(); ++i)
    {
        res = add_two(res, muls[i]);
    }

    //cout << "RES: " << res << endl;

    return res;
}

string sum_inner(string mul)
{
    int sum = 0;
    for(size_t i = 0; i != mul.size(); ++i)
    {
        int in = atoi( mul.substr(i,1).c_str() );
        //cout << sum << " + " << in << endl;
        sum += in;
    }
    return convertInt( sum );
}

int main(){
    string n1;
    string n2;
    std::ifstream file("super.in");
    if(file.is_open())
    {
        getline(file,n1);
        getline(file,n2);
    }

    //Trim newline character
    n1 = n1.substr(0,n1.size()-1);

    string mul = mul_two(n1,n2);

    cout << "FIN MUL: " << mul << endl;
    
    while(mul.size() != 1)
    {
        mul = sum_inner(mul);
        //cout << "MUL: " << mul << endl;
    }
    /*string s1 = sum_inner(n1);
    string s2 = sum_inner(n2);
    int m = atoi( s1.c_str() ) * atoi( s2.c_str() );
    string mul = convertInt(m);
    while( mul.size() != 1 ){
        mul = sum_inner( mul );
    }*/

    cout << "FIN: " << mul << endl;

    std::ofstream ofile("super.out");
    if(ofile.is_open())
    {
        ofile << mul;
    }
    
    return 0;
}
