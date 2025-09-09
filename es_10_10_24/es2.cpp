#include <iostream>
using namespace std;

void controllo (char lettera);
void minus_to_maius (char minus);

int main (){
 char a;
 cout<<"inserisci un carattere dell'alfabeto"<<endl;
 cin>>a;

 controllo(a);
 
 return 0;
}

void controllo (char lettera){
 if(lettera>96&&lettera<123){
  minus_to_maius(lettera);
 }else{
  cout<<"ERRORE, carattere inserito errato";
 }
}

void minus_to_maius (char minus){
 char maiusc;
 maiusc=minus-32;
 cout<<maiusc<<endl;
}
 