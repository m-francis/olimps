/* 
 * File:   ns.cpp
 * Author: Martins Francis
 *
 * Created on 13 March 2012, 17:26
 */
#include <fstream>
#include <sstream>

int main() {
    int i, arr[9] = {};
    
    std::string line;
    
    std::ifstream infile("ns.dat");
    while (infile >> line) {
        std::stringstream num(line);
        i = 0; char c;
        while(num >> c)
        {
            arr[i++] += c - '0';
        }
    }
    
    std::ofstream outfile("ns.rez");
    for (int r = 0; r < i; r++ ) {
        outfile << 45 - arr[r];
    }
    outfile.close();

    return 0;
}

//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <cstdlib>
//
//using std::cout;
//using std::endl;
//using std::string;
//using std::vector;
//
//string convertInt(int number)
//{
//   std::stringstream ss;
//   ss << number;
//   return ss.str();
//}
//
//int main2() {
//    vector<string> nums;
//    size_t len;
//    
//    std::ifstream ifile("ns.dat");
//    if (ifile.is_open()) {
//        string s;
//        for(int i = 0; i < 8; ++i){
//            getline(ifile,s);
//            len = s.length(); //pedejais bez newline parraksta
//            nums.push_back(s);
//        }
//    }
//
//    string ret = "";
//    for(size_t i = 0; i < len; ++i){
//        int sum = 0;
//        for(int k = 0; k < 8; ++k){
//            string num = nums[k];
//            sum += atoi( num.substr(i,1).c_str() );
//        }
//        int diff = 45 - sum;
//        ret.append(convertInt(diff));
//    }
//
//    cout << "FIN: " << ret << endl;
//
//    std::ofstream ofile("ns.rez");
//    if (ofile.is_open()) {
//        ofile << ret;
//    }
//
//    return 0;
//}
//
