//CIFRARIO DI CESARE
#include <iostream>
#include <fstream>
#include "es1_cesare.h"
using namespace std;

int main(int argc, char * argv[]){
 fstream myin,myout;
 //CONTROLLO CHE L'INPUT DA CMDLINE SIA CORRETTO
 if (argc!=4) {
  cerr << "ERRORE, input previsto: <./a.out> <filename_in> <filename_out> <key>"<<endl;
  return 0;
 }
 //APRO IL FILE IN E CONTROLLO CHE NON VADA IN FAIL
 myin.open(argv[1],ios::in);
 if (myin.fail()) {
  cerr << "Il file " << argv[1] << " non esiste\n";
  return 0;
 }
 //APRO IL FILE OUT E CONTROLLO CHE NON VADA IN FAIL
 myout.open(argv[2],ios::out);
 if (myin.fail()) {
  myin.close();
  cerr << "Il file " << argv[2] << " non esiste\n";
  return 0;
 }
 int chiave=atoi(argv[3]); //inizializzo la chiave
 cout<<"LA CHIAVE è: "<<chiave<<endl;

 char frase[256];
 myin.getline(frase,256); //copio il file_in sulla mia frase
 cout<<"la frase iniziale è:"<<endl<<frase<<endl<<endl;
 
 char choice;
 cout<<"scegliere se cifrare (c) o decifrare (d) il messaggio"<<endl;
 cin>>choice;

 switch(choice){
  case 'c':
  crypt(frase,chiave);
  cout<<"il messaggio cifrato è: "<<frase<<endl;
  myout<<frase;
  break;
  case 'd':
  decrypt(frase,chiave);
  cout<<"il messaggio decifrato è:"<<frase<<endl;
  myout<<frase;
  break;
  default:
  cout<<"ERRORE, scelta errata"<<endl;
  break;
 }

 myin.close();
 myout.close();
 return 0;
}