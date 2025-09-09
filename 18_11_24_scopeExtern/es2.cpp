//ESTRAI SOLO LE MAIUSCOLE
#include <iostream>
#include "es2_estrai.h"
using namespace std;

int main(){
 char frase[MAX_DIM];
 cout<<"inserire una stringa di massimo 80 caratteri senza spazi"<<endl;
 cin>>frase;

 char *risultato= new char [MAX_DIM];
 risultato=estrai_stringa(frase);
 cout<<"l'estratto delle maiuscole è: "<<risultato<<endl;

 delete[] risultato;
}