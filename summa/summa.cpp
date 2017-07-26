#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <typeinfo>

using std::cout;
using std::endl;

/*
 * Returns the length of the char array
 */
int clen(char c[]){
    int len = 0;
    for(int i = 0; c[i] != '\0'; ++i){
        len++;
    }
    return len;
}

/*
 * Shifts the last digit to the front of the number
 */
int shift(int num){
    char init[10];
    sprintf(init, "%d", num);
    int len = clen(init);
    char newc[len];
    
    newc[0] = init[len-1];
    for(int i = 1; i != len; ++i){
        newc[i] = init[i-1];
    }

    int nc = atoi(newc);
    
    //cout << init << " " << newc << " " << nc << endl;

    return nc;
}

int main(){
    //Read input
    std::ifstream file("summa.in");
    int num;
    if(file.is_open()){
        file >> num;
    } else return 0;

    char init[10];
    sprintf(init, "%d", num);
    int len = clen(init);

    int sum = num;
    for(int i = 0; i < len-1; ++i){
        num = shift(num);
        //cout << "adding " << num << endl;
        sum += num;
    }

    cout << sum << endl;

    //Write to output file
    std::ofstream outfile("summa.out");
    if(outfile.is_open()){
        outfile << sum;
    } else return 0;

    return 0;
}
