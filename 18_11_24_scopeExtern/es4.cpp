//TRIS
#include <iostream>
#include "es4_tris.h"
using namespace std;

int main(){
 cout<<"avvio una partita a tris:"<<endl<<endl;
 iniziaGioco();

 char a;
 cout<<"per ripetere il gioco inserire (r) altrimenti inserire un carattere casuale:"<<endl<<endl;
 cin>>a;
 while (a=='r'){
  iniziaGioco();
  cout<<"per ripetere il gioco inserire (r) altrimenti inserire un carattere casuale:"<<endl<<endl;
  cin>>a;
 }
 return 0;
}