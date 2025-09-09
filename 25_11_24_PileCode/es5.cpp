#include <iostream>
#include <cstring>
#include <cstdlib>
#include "coda_int.h"
#include "pila_int.h"
using namespace std;

int main(){
 pila_init();
 coda_init();
 
 /*nodoPila *testa= new (nothrow) nodoPila;
 testa=NULL;
 listaPila nuovoNodo = new (nothrow) nodoPila;
 nuovoNodo->value = 10;
	nuovoNodo->next = testa;
	testa = nuovoNodo;*/
 
 coda *A=new coda;
 A->head=NULL;
 listaCoda nuovoNodo1 = new (nothrow) nodoCoda;
 nuovoNodo1->value=10;
 nuovoNodo1->next=NULL;
 A->head=nuovoNodo1;
 A->tail=nuovoNodo1;
 listaCoda nuovoNodo2 = new (nothrow) nodoCoda;
 nuovoNodo2->value=10;
 nuovoNodo2->next=NULL;
 A->tail->next=nuovoNodo2;
 A->tail=nuovoNodo2;


 char parola[41];
 cout<<"inserisci una parola"<<endl;
 cin>>parola;

 for(int i=0;parola[i]!='\0';i++){
  coda_enqueue(parola[i]);
  pila_push(parola[i]);
 }

 bool check=true;
 int a,b; 
 while(pila_top(a)){
  pila_top(a);
  coda_first(b);
  if(a!=b){
   check=false;
  }
  pila_pop();
  coda_dequeue();
 }

 if(check){
  cout<<"la parola è palindroma"<<endl;
 }else {
  cout<<"la parola NON è palindroma"<<endl;
 }

 pila_deinit();
 coda_deinit();
 return 0;
}