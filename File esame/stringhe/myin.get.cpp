#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;


int main(int argc, char * argv []) {
  fstream myin;

 if (argc!=2) {
  cerr << "ERRORE, input previsto: ./a.out <filename_in>"<<endl;
  return 0;
 }

 myin.open(argv[1],ios::in);
 if (myin.fail()) {
  cerr << "Il file " << argv[1] << " non esiste\n";
  return 0;
 }

    char temp;
    while(!myin.eof()){
        myin.get(temp);  
        //QUA STO SCORRENDO TUTTO IL FILE LETTERA PER LETTERA      
    }

   myin.close();
   myin.open(argv[1],ios::in); //chiudo e riapro per ripartire da capo a leggere il file

    char word[255];
    while(!myin.eof()){
        myin>>word;
        //QUA STO SCORRENDO TUTTO IL FILE UNA PAROLA ALLA VOLTA      
    }

 myin.close();
 return 0;
}
