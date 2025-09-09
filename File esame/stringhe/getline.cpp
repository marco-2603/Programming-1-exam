using namespace std;
#include <iostream>
#include <cstdlib>
#include <fstream>

int main(int argc, char * argv[]){
 fstream myin;

 myin.open(argv[1],ios::in);
 if (myin.fail()) {
  cerr << "Il file " << argv[1] << " non esiste\n";
  return 0;
 }

 char riga[200];
 myin.getline(riga,200);

 return 0;
}
