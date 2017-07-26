#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <cstdlib>
#include <string>
#include <string.h>

using std::cout;
using std::endl;

std::string convertInt(int number)
{
   std::stringstream ss;
   ss << number;
   return ss.str();
}

std::string subtract(std::string num, std::string div)
{  
    std::string div_s;
    for(int i = 0; i < num.size() - div.size(); ++i)
    {
        div_s.append("0");
    }
    div_s.append(div);
    
    //cout << "SUB: " << num << endl;
    //cout << "   : " << div_s << endl;

    std::string new_s;

    num = std::string ( num.rbegin(), num.rend() ); //reverse string
    div_s = std::string ( div_s.rbegin(), div_s.rend() ); //reverse string

    int carry = 0;
    for(int i = 0; i < num.size(); ++i)
    {
        int dg1 = atoi(num.substr(i,1).c_str());
        int dg2 = atoi(div_s.substr(i,1).c_str());
        //cout << "sub: " << dg1 << " " << dg2 << endl;

        dg2 += carry;
        
        if(dg1 >= dg2) {
            int dif = dg1-dg2;
            new_s.append( convertInt(dif) );
            carry = 0;
        } else {
            dg1 += 10;
            new_s.append( convertInt(dg1-dg2) );
            carry = 1;
        }
    }

    //Remove leading zeros
    std::string::reverse_iterator rit;
    for ( rit=new_s.rbegin() ; rit < new_s.rend(); rit++ )
    {
        if(*rit != '0')
        {
            new_s = std::string( rit, new_s.rend() );
            break;
        }
    }

    //cout << "FIN: " << new_s << endl;
    
    return new_s;
}

int main(){
    std::string line1;
    std::string line2;

    std::ifstream file("atlikums.in");
    if(file.is_open()){
        getline(file,line1);
        getline(file,line2);
    }

    line1 = line1.substr(0,line1.size()-1); //Get rid of new-line character

    cout << line1.size() << endl;

    int c = 0;

    while( line1.size() > 9 ){
        ++c;
        std::string div = line2;

        //while( div.size() < (line1.size() - line2.size() - 1) )
        //    div.append( line2 );

         while( div.size() < (line1.size() - 1) )
            div.append( "0" );

        if(div.substr(0,1) < line1.substr(0,1) ){
            div.append( "0" );
        }

        //cout << line1 << endl;
        //cout << div << endl;

        line1 = subtract(line1, div);
    }

    cout << "TOT SUBS: " << c << endl;

    long num = atoi(line1.c_str());
    long div = atoi(line2.c_str());

    cout << "FINAL: " << num << " % " << div << endl;

    long mod = num % div;

    cout << mod << endl;

    //Write to output file
    std::ofstream outfile("atlikums.out");
    if(outfile.is_open()){
        outfile << mod;
    } else return 0;

    return 0;
}
