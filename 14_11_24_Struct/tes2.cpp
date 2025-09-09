// struttura base collisione blocchi
#include <iostream>
#include <cstdlib>
using namespace std;

struct CoffeMachine{
 int caffe;
 double credito;
};

void addCoin(CoffeMachine * machine, int val){
 machine->credito+=val;
}

bool getCoffe(CoffeMachine * machine){
 if(machine->credito>0.39||machine->caffe>1){
  machine->caffe-=1;
  machine->credito-=0.39;
  return true;
 } else return false;
}

int main(){
 CoffeMachine machine;
 char s;
 int val;

 cout<<"inserire i valori iniziali di caffe: ";
 cin>> machine.caffe;
 cout<<" e di credito: ";
 cin>> machine.credito;
 cout<<endl;

 do{
  cout<<"scegliere l'azione da compiere:"<<endl;
  cout<<"inserire monete (i)"<<endl;
  cout<<"prendere un caffe (c)"<<endl;
  cout<<"sapere il credito (m)"<<endl;
  cout<<"esci (e)"<<endl;
  cout<<"premere un qualisasi altro tasto per concludere"<<endl;
  cin>>s;

  switch(s){
   case 'i': cout<<"quanto credito si vuole inserire?"<<endl;
   cin>>val;
   addCoin(&machine,val);
   break;
   case 'c':if(getCoffe(&machine)){
    cout<<"caffe preso"<<endl;
   } else {
    cout<<"errore, credito o numero caffe insufficenti"<<endl;
   }
   break;
   case 'm':
   cout<<"il credito rimanente è: "<<machine.credito<<endl;
   break;
   case 'e':break;
   default: cout<<"scelta non capita"<<endl;
  }
 }while(s=='i' || s=='c' || s=='m');


 return 0;
}