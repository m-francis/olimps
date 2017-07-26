#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <typeinfo>

using std::cout;
using std::endl;

int main(){
    //Read input
    std::vector<int> data;
    std::ifstream file("skaitl2.in");
    std::copy(std::istream_iterator<int>(file), std::istream_iterator<int>(), std::back_inserter(data));

    int num = data[0];
    int c = data[1];

    char cc[1];
    sprintf(cc,"%d",c);
    int cci = (int)cc[0];

    //std::cout << num << " " << cc << " " << cci << std::endl;

    bool found = false;
    while(found == false){
        num += 1;
        //cout << "NEW num " << num << endl;
        char c_num[5];
        sprintf(c_num,"%d",num);

        for(int i = 0; i < 5; ++i){
            int ci = (int)c_num[i];
            if(ci >= 48 && ci <= 57){
                //cout << "comparing " << ci << " " << cci << " : "<< c_num[i] << " and " << cc << endl;
                if(ci == cci){
                    found = true;
                }
            } else break;
        }
    }

    cout << num << endl;

    //Write to output file
    std::ofstream outfile("skaitl2.out");
    if(outfile.is_open()){
        outfile << num;
    } else return 0;

    return 0;
}
