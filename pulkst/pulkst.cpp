#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>
#include <vector>

using std::cout;    using std::endl;
using std::string;  using std::set;

string int_array_to_string(int int_array[], int size_of_array){
    std::ostringstream oss("");
    for (int temp = 0; temp < size_of_array; temp++)
        oss << int_array[temp];
    return oss.str();
}

int main(){
    string inh, inm, in;
    std::ifstream ifile("pulkst.dat");
    if(ifile.is_open()){
        getline(ifile,inh,':');
        getline(ifile,inm);
        in = inh.append(inm);
        cout << "IN: " << in << endl;
    }

    int n[4] = { atoi(inh.substr(0,1).c_str()),
                 atoi(inh.substr(1,1).c_str()),
                 atoi(inm.substr(0,1).c_str()),
                 atoi(inm.substr(1,1).c_str()) };

    std::sort(n,n+4);

    set<string> times;
    do{
        string s = int_array_to_string(n,4);
        string h = s.substr(0,2);
        string m = s.substr(2,2);
        int i = atoi(s.c_str());
        int j = atoi(h.c_str());
        int k = atoi(m.c_str());
        if(i <= 2359 && j <= 23 && k <= 59){
            times.insert( s );
        }
    } while( std::next_permutation(n, n+4) );

    cout << "perms done" << endl;

    std::vector<string> tv;
    set<string>::iterator it;
    for(it=times.begin(); it != times.end(); it++){
        string val = *it;
        cout << val << endl;
        tv.push_back(val);
    }

    std::sort(tv.begin(), tv.begin() + tv.size());

    cout << "sort done" << endl;

    string ret = "0000";
    int inint = atoi(in.c_str());
    for(size_t i = 0; i < tv.size(); ++i){
        string curr = tv[i];
        cout << "curr: " << curr << endl;
        int currint = atoi(curr.c_str());
        if(currint == inint){
            cout << "FOUND" << endl;
            if(i+1 == tv.size()){
                cout << "ret first" << endl;
                ret = tv[0];
            } else{
                cout << "ret next" << endl;
                ret = tv[i+1];
            }
            cout << "RET: " << ret << endl;
            break;
        }
    }

    //string ret;
    //if(pos+1 != tv.size())
    //    ret = tv[pos+1];
    //else
    //    ret = tv[0];

    /*set<string>::iterator it;

    for(it=times.begin(); it != times.end(); it++){
        cout << *it << endl;
    }

    it = times.find(in);
    if(++it != times.end()){
        cout << "NEXT: " << *it << endl;
    } else{
        it = times.begin();
        cout << "NEXT END: " << *it << endl;
    }

    string ret = *it;*/

    ret = ret.substr(0,2).append(":").append(ret.substr(2,2));

    cout << "FIN: " << ret << endl;

    std::ofstream ofile("pulkst.rez");
    if(ofile.is_open()){
        ofile << ret;
    }

    return 0;
}
