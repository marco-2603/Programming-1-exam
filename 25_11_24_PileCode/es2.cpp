//CONTROLLO CARATTERI (parentesi bilanciate)
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "pila.h"

using namespace std;

int main(){
 pila_init();

 char s;
 int a,conta=0;
 cout<<"scrivere una serie di parentesi, per uscire inserire (e)"<<endl;
 do{
  cin>>s;
  if(s=='('||s==')'){
   pila_push(s);
  }
 }while(s=='('||s==')');

 cout<<endl<<"la pila ora è:"<<endl;
 pila == NULL;
 listaPila nodoCorrente = pila;
 do {
  cout << nodoCorrente->value << endl;
  nodoCorrente = nodoCorrente->next;
 } while (nodoCorrente != NULL);
 

 while(pila_top(a)){
  pila_pop();
  if(a=='('){
   conta++;
  }else if(a==')'){
   conta--;
  }
 }

 if(conta==0){
  cout<<"le parentesi sono bilanciate"<<endl;
 }else{
  cout<<"le parentesi NON sono bilanciate"<<endl;
 }


 return 0;
}