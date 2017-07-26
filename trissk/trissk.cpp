/* 
 * File:   trissk.cpp
 * Author: Martins Francis
 *
 * Created on 03 March 2012, 20:35
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

int main() {
    int a,b,c;
    std::ifstream ifile("trissk.dat");
    if (ifile.is_open()) {
        string as,bs,cs;
        getline(ifile,as,' ');
        getline(ifile,bs,' ');
        getline(ifile,cs);
        a = atoi(as.c_str());
        b = atoi(bs.c_str());
        c = atoi(cs.c_str());
    }

    cout << a << " " << b << " " << c << endl;

    string pos = "NEVAR";
    string zero = "NEVAR";
    string neg = "NEVAR";

    //int sum1 = a + b;
    //int sum2 = a + c;
    //int sum3 = b + c;

    //cout << "1: " << sum1 << "   2: " << sum2 << "   3: " << sum3 << endl;

    //positive
    if(a > 0 && b > 0 || a > 0 && c > 0 || b > 0 && c > 0){
        pos = "VAR";
    } else{
        if(a >= 0 && b <= 0 && a + b > 0){
            pos = "VAR";
        } else if(a <= 0 && b >= 0 && a + b > 0){
            pos = "VAR";
        } else if(a >= 0 && c <= 0 && a + c > 0){
            pos = "VAR";
        } else if(a <= 0 && c >= 0 && a + c > 0){
            pos = "VAR";
        } else if(c >= 0 && b <= 0 && c + b > 0){
            pos = "VAR";
        } else if(c <= 0 && b >= 0 && c + b > 0){
            pos = "VAR";
        }
    }

    //negative
    if(a < 0 && b < 0 || a < 0 && c < 0 || b < 0 && c < 0){
        neg = "VAR";
    } else{
        if(a >= 0 && b <= 0 && a + b < 0){
            neg = "VAR";
        } else if(a <= 0 && b >= 0 && a + b < 0){
            neg = "VAR";
        } else if(a >= 0 && c <= 0 && a + c < 0){
            neg = "VAR";
        } else if(a <= 0 && c >= 0 && a + c < 0){
            neg = "VAR";
        } else if(c >= 0 && b <= 0 && c + b < 0){
            neg = "VAR";
        } else if(c <= 0 && b >= 0 && c + b < 0){
            neg = "VAR";
        }
    }

    //zero
    if(a >= 0 && b <= 0 && a + b == 0){
        zero = "VAR";
    } else if(a <= 0 && b >= 0 && a + b == 0){
        zero = "VAR";
    } else if(a >= 0 && c <= 0 && a + c == 0){
        zero = "VAR";
    } else if(a <= 0 && c >= 0 && a + c == 0){
        zero = "VAR";
    } else if(c >= 0 && b <= 0 && c + b == 0){
        zero = "VAR";
    } else if(c <= 0 && b >= 0 && c + b == 0){
        zero = "VAR";
    }

    /*if(sum1 > 0 || sum2 > 0 || sum3 > 0){
        pos = "VAR";
    }
    if(sum1 == 0 || sum2 == 0 || sum3 == 0){
        zero = "VAR";
    }
    if(sum1 < 0 || sum2 < 0 || sum3 < 0){
        neg = "VAR";
    }*/

    cout << pos << endl;
    cout << zero << endl;
    cout << neg << endl;
    

    std::ofstream ofile("trissk.rez");
    if (ofile.is_open()) {
        ofile << pos << '\n';
        ofile << zero << '\n';
        ofile << neg;
    }

    return 0;
}

