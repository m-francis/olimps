#include <iostream>
#include <fstream>

int main(){
    char * rinda;
    std::ifstream is;
    is.open ("latv.in", std::ios::binary );

    // get length of file:
    is.seekg (0, std::ios::end);
    int len = is.tellg();
    is.seekg (0, std::ios::beg);

    // allocate memory:
    rinda = new char [len];

    // read data as a block:
    is.read (rinda,len);
    is.close();

    for(int i = 1; i != len; ++i){
        char c1 = rinda[i];
        char c2 = rinda[i-1];
        if( c1 == 'a' && c2 == 'a' 
                || c1 == 'e' && c2 == 'e'
                || c1 == 'u' && c2 == 'u'
                || c1 == 'i' && c2 == 'i' ){

            rinda[i] = '\0';
        } else if(c1 == 'j'){
            if( c2 == 'g' || c2 == 'l' || c2 == 'k' || c2 == 'n' ){
                rinda[i] = '\0';
            }
        } else if(c1 == 'h'){
            if( c2 == 'c' || c2 == 's' || c2 == 'z' ){
                rinda[i] = '\0';
            }
        } else continue;
    }

    int count = 0;
    for(int i = 0; i != len; ++i){
        if(!(rinda[i] == '\0' || rinda[i] == ' '))
            ++count;
    }

    std::cout << rinda << " : " << count << std::endl;

    std::ofstream ofile("latv.out");
    if(ofile.is_open()){
        ofile << count;
    }
    
    return 0;
}
