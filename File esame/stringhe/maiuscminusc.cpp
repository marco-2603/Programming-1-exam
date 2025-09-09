using namespace std;
#include <iostream>
#include <cstdlib>
#include <fstream>

int main(int argc, char * argv[]){
    char c,C;
    cin>>c;

    if(c>='a'&&c<='z'){
        C=c-('a' - 'A'); //toupper
    }
    if(c>='A'&&c<='Z'){
        C=c+('a' - 'A'); //tolower
    }

    return 0;
}
