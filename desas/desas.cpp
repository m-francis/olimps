#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using std::cout; using std::endl; using std::string;

//Checks if every character in string is unique
bool unique(string s){
    bool is = true;
    for(size_t i = 0; i < s.size(); ++i){
        string c = s.substr(i,1);
        if(s.find(c,i+1) != -1){
            is = false;
            break;
        }
    }
    return is;
}

bool numeric(string s){
    string vals = "123456789";
    bool is = true;
    for(size_t i = 0; i < s.size(); ++i){
        string c = s.substr(i,1);
        if( !(vals.find(c,0) != -1) ){
            is = false;
        }
    }
    return is;
}

std::string convertInt(int number)
{
   std::stringstream ss;
   ss << number;
   return ss.str();
}

bool won(string seq){
    if(seq.length() < 3)
        return false;

    if( seq.find("1") != -1 && seq.find("2") != -1 && seq.find("3") != -1 ) return true;
    if( seq.find("4") != -1 && seq.find("5") != -1 && seq.find("6") != -1 ) return true;
    if( seq.find("7") != -1 && seq.find("8") != -1 && seq.find("9") != -1 ) return true;
    if( seq.find("1") != -1 && seq.find("4") != -1 && seq.find("7") != -1 ) return true;
    if( seq.find("2") != -1 && seq.find("5") != -1 && seq.find("8") != -1 ) return true;
    if( seq.find("3") != -1 && seq.find("6") != -1 && seq.find("9") != -1 ) return true;
    if( seq.find("1") != -1 && seq.find("5") != -1 && seq.find("9") != -1 ) return true;
    if( seq.find("3") != -1 && seq.find("5") != -1 && seq.find("7") != -1 ) return true;

    return false;
}

int main(){
    string neko = "NEKOREKTS";
    string pirm = "PIRMAIS";
    string otra = "OTRAIS";
    string nevi = "NEVIENS";
    
    string in;
    std::ifstream ifile("desas.in");
    if(ifile.is_open()){
        ifile >> in;
    }

    string ret;

    if(in.size() <= 9 && unique(in) && numeric(in)){
        string f, s;
        bool winner = false;
        bool nekor;

        for(size_t i = 1; i <= in.size(); ++i){
            cout << i << endl;
            nekor = false;
            if( i % 2 == 0 ){ //set second
                s = s.append(in.substr(i-1,1));
                cout << "s: " << s << endl;
                if(won(s)){
                    if(i != in.size())
                        nekor = true;
                    winner = true;
                    ret = otra;
                    break;
                }
            } else{ //set first
                f = f.append(in.substr(i-1,1));
                cout << "f: " << f << endl;
                if(won(f)){
                    if(i != in.size())
                        nekor = true;
                    winner = true;
                    ret = pirm;
                    break;
                }
            }
        }

        if(winner == false && in.size() < 9)
            ret = neko;

        if(winner == false && in.size() == 9)
            ret = nevi;

        if(nekor == true) ret = neko;
        
    } else{
        ret = neko;
    }

    cout << ret << endl;

    std::ofstream ofile("desas.out");
    if(ofile.is_open()){
        ofile << ret;
    }
    return 0;
}
