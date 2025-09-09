#include <iostream>
using namespace std;

void controllo(char & x, char & y){
 if(y<x){
  cout<<"ERRORE, secondo carattere minore del primo, reinserirli"<<endl;
  cout<<"inserire due caratteri"<<endl;
  cin>>x>>y;
  controllo(x,y);
 }
 return;
}