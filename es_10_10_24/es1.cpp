#include <iostream>
using namespace std;

void controllo (char lettera);
char minus_to_maius (char minus);

int main (){
 char a;
 cout<<"inserisci un carattere dell'alfabeto"<<endl;
 cin>>a;

 controllo(a);

 return 0;
}

void controllo (char lettera){
 if(lettera>96&&lettera<123){
  cout<<minus_to_maius(lettera)<<endl;
 }else{
  cout<<"ERRORE, carattere inserito errato";
 }
}

char minus_to_maius (char minus){
 int maiusc;
 maiusc=minus-32;
 return maiusc;
}
 