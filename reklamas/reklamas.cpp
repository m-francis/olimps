/* 
 * File:   reklamas.cpp
 * Author: Martins Francis
 *
 * Created on 08 March 2012, 23:18
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;
using std::vector;

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
    //cout << "summing: " << n1 << " and " << n2 << endl;

    n1 = std::string ( n1.rbegin(), n1.rend() ); //reverse string
    n2 = std::string ( n2.rbegin(), n2.rend() ); //reverse string

    string final;
    int carry = 0;
    for(size_t i = 0; i != n1.length(); ++i)
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

/* Returns true if number represented by string n1 is greater than number
   represented by n2 */
bool compare(string n1, string n2)
{
    //cout << "comparing: " << n1 << " and " << n2; // << endl;
    
    bool first = true;
    if(n1.length() > n2.length()){
        return first;
    } else if(n1.length() < n2.length()){
        return !first;
    } else if(n1.compare(n2) == 0 ){
        return !first;
    } else{ //n1 and n2 of equal length
        for(size_t i = 0; i != n1.length(); ++i)
        {
            //compare each digit
            int i1 = atoi(n1.substr(i,1).c_str());
            int i2 = atoi(n2.substr(i,1).c_str());
            
            if( i1 == i2 )
                continue;
            else if( i1 > i2)
                return first;
            else
                return !first;
        }
        return first;
    }
}

string prepend_zeros(string prepend, size_t len){
    string zero;
    while(prepend.length() < len){
        zero = "0";
        prepend = zero.append(prepend);
    }
    return prepend;
}

/*
 * Multiply two strings consisting of natural numbers
 */
string mul_two(string n1, string n2){
    std::vector<string> muls;
    //cout << "MUL TWO: " << n1 << " : " << n2 << endl;

    n1 = std::string ( n1.rbegin(), n1.rend() ); //reverse string
    n2 = std::string ( n2.rbegin(), n2.rend() ); //reverse string

    for(size_t i = 0; i != n2.length(); ++i)
    {
        //cout << "ROUND: " << i << endl;
        string mul;
        int carry = 0;
        int dg2 = atoi( n2.substr(i,1).c_str() );
        //cout << "  dg2: " << dg2 << endl;

        for(size_t j = 0; j != n1.length(); ++j)
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
        if(longest < muls[i].length())
            longest = muls[i].length();
    }
    //cout << "long " << longest << endl;

    //Surround all strings with zeros so they are all the same length
    for(size_t i = 0; i != muls.size(); ++i)
    {
        if(muls[i].length() < longest)
        {
            string temp;
            while(temp.length() + muls[i].length() < longest)
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

string str_factorial (int n)
{
    string fact = "1";
    if(n <= 1)
        return "1";
    else{
        //fact  = n * factorial (n - 1);
        string ns = convertInt(n);
        string fn = str_factorial(n-1);
        ns = prepend_zeros(ns,fn.length());
        fn = prepend_zeros(fn,ns.length());
        fact = mul_two(ns, fn);
        //nonem vadosas nulles, ja ir
        while(fact.substr(0,1).compare("0") == 0)
        {
            fact = fact.substr(1,fact.length());
        }
    }
    return fact;
}

string remove_zeros(string s){
    //nonem vadosas nulles, ja ir
    while(s.substr(0,1).compare("0") == 0)
    {
        s = s.substr(1,s.length());
    }

    if(s.length() == 0)
        return "0";
    
    return s;
}

/*
 * Unsigned number division n1 / n2
 */
string div(string n1, string n2){
    //http://mathforum.org/library/drmath/view/57919.html
    
    int i2 = atoi(n2.c_str());
    string final = "";
    string dividing = "";
    for(size_t i = 0; i < n1.length(); ++i){
        dividing.append(n1.substr(i,1));
        int num = atoi(dividing.c_str());
        if( num >= i2 ){
            int division = num / i2;
            int modulus = num % i2;

            final.append(convertInt(division));
            dividing = convertInt(modulus);
        } else{
            if(final.length() < i + 1)
                final.append("0");
            continue;
        }
    }

    final = remove_zeros(final);

    return final;
}

string subtract1(string s){
    string add = "";
    for(size_t i = s.length()-1; i >= 0; --i){
        int last = atoi(s.substr(i,1).c_str());
        if(last == 0){
            add.append("9");
        } else{
            int new_last = last - 1;
            s = s.substr(0,i).append(convertInt(new_last)).append(add);
            break;
        }
    }
    return s;
}

/*
 * Return the sum of all numbers from 1 to s
 */
string str_sum(string s){
    //cout << "STR_SUM: " << s << endl;
    
    string last = s.substr(s.length()-1,1);
    int last_i = atoi(last.c_str());

    bool even = true;
    string ss = s;
    if(last_i % 2 != 0){
        even = false;
        s = subtract1(s);
    }

    string one = prepend_zeros("1",s.length());

    string division = div(s,"2");
    string sum = add_two(s,one);
    string mul = mul_two(sum,division);

    if(!even){
        mul = prepend_zeros(mul,ss.length());
        ss = prepend_zeros(ss,mul.length());
        mul = add_two(mul,ss);
    }

    mul = remove_zeros(mul);

    return mul;
}

int main() {
    string n,k,m;
    std::ifstream ifile("reklamas.dat");
    if (ifile.is_open()) {
        getline(ifile,n,' ');
        getline(ifile,k,' ');
        ifile >> m;
    }

    cout << "m: " << m << endl;

    string subsum = n;
    int day = 1;
    int ni = atoi(n.c_str());
    int step = 1;
    bool backward = false;
    
    while(true)
    {
        //x * n
        string mul = convertInt(day * ni);
        //cout << "sum: " << sum << endl;

        //(x-1)!!
        string sum = str_sum( convertInt(day-1) );
        //cout << "str_sum: "<< sum << endl;

        //(x-1)!! * k
        string sum_mul = mul_two(sum,k);
        sum_mul = remove_zeros(sum_mul);
        //cout << "sum mul: " << sum_mul << endl;

        //x * n + (x-1)!! * k
        mul = prepend_zeros(mul,sum_mul.length());
        sum_mul = prepend_zeros(sum_mul,mul.length());
        subsum = add_two(mul, sum_mul);
        subsum = remove_zeros( subsum );

        cout << day << ": " << subsum << endl;

        if(compare(m,subsum)){
            if(!backward)
                step *= 10;
            day += step;
        } else if(m.compare(subsum) == 0){
            break;
        } else{
            if(step == 1)
                break;
            else{
                day -= step;
                step /= 10;
                backward = true;
            }
        }
    }

    cout << day << endl;

    //return 0;





    

    //cout << str_sum("2000000000000000") << endl;

    //return 0;

    /*cout << "m: " << m << endl;

    string subsum = n;
    int day = 1;
    int ni = atoi(n.c_str());

    string prev_subsum;
    int step = 100000;
    
    while( compare(m,subsum) && m.compare(subsum) != 0 ){
        prev_subsum = subsum;
        
        //x * n
        string sum = convertInt(day * ni);
        //cout << "sum: " << sum << endl;

        //(x-1)!! * k
        string fact = str_sum(convertInt(day-1));
        //cout << "str_sum: "<< fact << endl;
        //string ks = prepend_zeros(k, fact.length());
        //cout << "ks: "<< ks << endl;
        string fkmul = mul_two(fact,k);
        fkmul = remove_zeros(fkmul);
        //cout << "fkmul: " << fkmul << endl;

        //x * n + (x-1)!! * k
        sum = prepend_zeros(sum,fkmul.length());
        fkmul = prepend_zeros(fkmul,sum.length());
        subsum = add_two(sum, fkmul);
        subsum = remove_zeros( subsum );
        
        cout << day << ": " << subsum << endl;

        day += step;
    }

    cout << "exit with prev subsum: " << prev_subsum << " and day: " << day << endl;

    day -= step*2;

    while( compare(m,prev_subsum) && m.compare(prev_subsum) != 0 ){
        //x * n
        string sum = convertInt(day * ni);
        //cout << "sum: " << sum << endl;

        //(x-1)!! * k
        string fact = str_sum(convertInt(day-1));
        //cout << "str_sum: "<< fact << endl;
        //string ks = prepend_zeros(k, fact.length());
        //cout << "ks: "<< ks << endl;
        string fkmul = mul_two(fact,k);
        fkmul = remove_zeros(fkmul);
        //cout << "fkmul: " << fkmul << endl;

        //x * n + (x-1)!! * k
        sum = prepend_zeros(sum,fkmul.length());
        fkmul = prepend_zeros(fkmul,sum.length());
        prev_subsum = add_two(sum, fkmul);
        prev_subsum = remove_zeros( prev_subsum );

        cout << day << ": " << prev_subsum << endl;

        ++day;
    }*/

    /*//kamer m ir lielaks par reklamu summu, vai ari abi vienadi...
    while( compare(m,subsum) && subsum.compare(m) != 0 )
    {
        //reklamas sodien
        isum = convertInt( ni + ki * day );

        //lai saskaititu vajag vienadu skaitu ciparu
        isum = prepend_zeros(isum, subsum.length());
        subsum = prepend_zeros(subsum, isum.length());

        //pieskaita sodienas reklamu skaitu kopejam reklamu skaitam
        subsum = add_two(subsum, isum);

        //nonem vadosas nulles, ja ir
        while(subsum.substr(0,1).compare("0") == 0)
        {
            subsum = subsum.substr(1,subsum.length());
        }

        cout << " subsum: " << subsum << endl;
        
        ++day;
    }

    cout << day-1 << endl;*/

    std::ofstream ofile("reklamas.rez");
    if (ofile.is_open()) {
        ofile << day;
    }

    return 0;
}

