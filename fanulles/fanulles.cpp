#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using std::cout;
using std::endl;

int main(){
    long num;
    std::ifstream ifile("fanulles.in");
    if(ifile.is_open()){
        ifile >> num;
    }

    //
    //http://www.purplemath.com/modules/factzero.htm
    //http://answers.google.com/answers/threadview/id/509662.html
    //

    int sum = 0;
    int mul = 5;
    int div = 1;
    
    while(div != 0){
        div = num / mul;
        sum += div;
        mul *= 5;
        //cout << "MUL: " << mul << " DIV: " << div << " SUM: " << sum << endl;
    }

    cout << sum << endl;

    std::ofstream ofile("fanulles.out");
    if(ofile.is_open()){
        ofile << sum;
    }

    return 0;
}
