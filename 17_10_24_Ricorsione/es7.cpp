//STAMPA CARATTERI
#include <iostream>
using namespace std;

void stampacar(int x, int y);
void controllo(char & x, char & y);

int main (){
 char x,y;
 cout<<"inserire due caratteri"<<endl;
 cin>>x>>y;
 controllo(x,y);
 cout<<"li caratteri tra questo intervallo sono: "<<endl; 
 stampacar(x,y);
 cout<<endl;

 return 0;
}

void controllo(char & x, char & y){
 if(y<x){
  cout<<"ERRORE, secondo carattere minore del primo, reinserirli"<<endl;
  cout<<"inserire due caratteri"<<endl;
  cin>>x>>y;
  controllo(x,y);
 }
 return;
}

void stampacar(int x, int y){
 if(x==y){
  cout<<char(x)<<" ";
  return;
 }else{
  cout<<char(x)<<" ";
  stampacar(x+1,y);
 }
 return;
}
