#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;

std::string convertInt(int number)
{
   std::stringstream ss;
   ss << number;
   return ss.str();
}

int main(){
    vector<int> nums;
    std::ifstream file("cipvirk.in");
    std::copy(std::istream_iterator<int>(file), std::istream_iterator<int>(), std::back_inserter(nums));

    int max = nums[2];

    cout << nums[0] << endl;
    cout << nums[1] << endl;

    nums.resize(2);
    
    for(int i = 2; i < max; ++i ){
        int t = nums[i-1] + nums[i-2];
        //cout << t << endl;
        string ts = convertInt(t);
        //cout << ts << endl;
        string dg = ts.substr(ts.size()-1,1);
        //cout << ts << " : " << dg << endl;
        nums.push_back( atoi( dg.c_str() ) );
    }

    cout << nums[max-1] << endl;

    std::ofstream ofile("cipvirk.out");
    if(ofile.is_open()){
        ofile << nums[max-1];
    }

    return 0;
}
