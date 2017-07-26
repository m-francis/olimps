#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>
#include <cstdlib>

using std::cout;    using std::endl;
using std::string;  using std::set;
using std::pair;

typedef std::pair<int, int> IntPair;

set<IntPair> addA(set<IntPair> pairs, int col, int row){
    pairs.insert(IntPair(col,row));
    pairs.insert(IntPair(col,row-1));
    pairs.insert(IntPair(col,row-2));
    pairs.insert(IntPair(col+1,row-2));
    pairs.insert(IntPair(col+2,row-2));

    return pairs;
}

set<IntPair> addB(set<IntPair> pairs, int col, int row){
    pairs.insert(IntPair(col,row));
    pairs.insert(IntPair(col+1,row));
    pairs.insert(IntPair(col,row-1));
    pairs.insert(IntPair(col+1,row-1));
    pairs.insert(IntPair(col,row-2));

    return pairs;
}

set<IntPair> addC(set<IntPair> pairs, int col, int row){
    pairs.insert(IntPair(col,row));
    pairs.insert(IntPair(col,row+1));
    pairs.insert(IntPair(col-1,row));
    pairs.insert(IntPair(col-2,row));
    pairs.insert(IntPair(col-3,row));

    return pairs;
}

int main(){
    set<IntPair> pairs;
    std::ifstream ifile("pentam1.in");
    if(ifile.is_open()){
        string cs;
        getline(ifile, cs);
        int count = atoi(cs.c_str());

        for(int i = 0; i < count; ++i){
            string pent; //a b c
            getline(ifile, pent,' ');
            string cols;
            getline(ifile, cols,' ');
            string rows;
            getline(ifile, rows);
            
            int col = atoi(cols.c_str());
            int row = atoi(rows.c_str());
            
            cout << "PENT: " << pent << " COL: " << col << " ROW: " << row << endl;

            if(pent.compare("A") == 0)
                pairs = addA(pairs,col,row);
            else if(pent.compare("B") == 0)
                pairs = addB(pairs,col,row);
            else if(pent.compare("C") == 0)
                pairs = addC(pairs,col,row);
        }
    }

    cout << pairs.size() << endl;

    std::ofstream ofile("pentam1.out");
    if(ofile.is_open()){
        ofile << pairs.size();
    }
    return 0;
}
