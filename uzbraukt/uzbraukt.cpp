/* 
 * File:   uzbraukt.cpp
 * Author: Martins Francis
 *
 * Created on 10 March 2012, 09:32
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    //http://www.comp.nus.edu.sg/~noi/tasks2000.html
    int up = 0; int down = 0; int level = 0;
    vector<int> steps;
    
    std::ifstream ifile("uzbraukt.dat");
    if (ifile.is_open()) {
        string els;
        getline(ifile,els);

        string num;
        while(getline(ifile,num)){
            int n = atoi(num.c_str());
            steps.push_back(n);
        }
        steps.push_back(steps[0]);

        bool up_flag = false; bool down_flag = false; bool level_flag = false;
        for(int i = 1; i < steps.size(); ++i){
            if(steps[i-1] < steps[i] && !up_flag){
                up_flag = true; down_flag = false; level_flag = false;
                ++up;
            } else if(steps[i-1] > steps[i] && !down_flag){
                up_flag = false; down_flag = true; level_flag = false;
                ++down;
            } else if(steps[i-1] == steps[i] && !level_flag){
                up_flag = false; down_flag = false; level_flag = true;
                ++level;
            }
        }
    }

    cout << "UP: " << up << endl;
    cout << "DOWN: " << down << endl;
    cout << "LEVEL: " << level << endl;

    std::ofstream ofile("uzbraukt.rez");
    if (ofile.is_open()) {
        ofile << up << " " << down << " " << level;
    }

    return 0;
}

