/* 
 * File:   pirmreiz.cpp
 * Author: Martins Francis
 *
 * Created on 03 March 2012, 22:38
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;

bool is_prime(long n){
    if(n == 2 || n == 3)
        return true;
    
    long half = (n / 2) + 1;
    bool even = false;
    //double sqr = sqrt(n);
    for(long i = 2; i <= half; ++i){
        even = true;
        if(n % i == 0){
            even = false;
            break;
        }
    }
    return even;
}

int main() {
    long num;
    std::ifstream ifile("pirmreiz.dat");
    if (ifile.is_open()) {
        ifile >> num;
    }

    cout << num << endl;

    //http://www.wikihow.com/Check-if-a-Number-Is-Prime

    //test primes
    /*for(long i = 0; i < num; ++i){
        bool prime = is_prime(i);
        if(prime)
            cout << i << " : " << prime << endl;
    }*/

    std::vector<long> primes;

    if(is_prime(num)){
        primes.push_back(num);
    } else{
        long half = (num / 2) + 1;
        for(long i = 2; i <= half; ++i){
            if(num % i == 0 && is_prime(i))
                primes.push_back(i);
        }
    }

    for(size_t i = 0; i < primes.size(); ++i){
        cout << primes[i] << endl;
    }

    std::ofstream ofile("pirmreiz.rez");
    if (ofile.is_open()) {
        for(long i = 0; i < primes.size(); ++i){
            ofile << primes[i] << endl;
        }
    }

    return 0;
}

