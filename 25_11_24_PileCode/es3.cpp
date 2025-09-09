//CODA BASE STRINGHE CON SWITCH SCELTA, ESERCIZIO POSTE
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "coda_str.h"

using namespace std;

int main(){

 init();

 char s;
 char a[31];
 do{
  cout<<endl<<"scegliere l'azione da compiere:"<<endl;
  cout<<"aggiungi persona (e)"<<endl;
  cout<<"smaltisci persona (d)"<<endl;
  cout<<"stampa situazione corrente (s)"<<endl;
  cout<<"premere un qualisasi altro tasto per concludere"<<endl;
  cin>>s;

  switch(s){
   case 'e':
   cout<<"scrivere il nome della persona da inserire"<<endl;
   cin>>a;
   if(isInQueue(a)){
    cout<<"errore,"<<a<<" è gia in coda"<<endl;
   }else if(!enqueue(a)){
    cout<<"ERRORE "<<endl;
   }

   break;
   case 'd':
   if(!dequeue()){
    cout<<"ERRORE coda vuota"<<endl;
   }
   break;
   case 's':
   print();
   break;
   default: cout<<"scelta non capita"<<endl;
  }
 }while(s=='e' || s=='d'|| s=='s');

 deinit();

 return 0;
}
