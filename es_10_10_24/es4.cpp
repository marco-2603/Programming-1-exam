#include <iostream>
#include <cstdlib>
using namespace std;

int tira_dado ();

int main (){
 srand(time(NULL));
 int n,dado,counter=0;

 for(int i=0;i<10;i++){
  dado=tira_dado();
  if(dado==1){
   counter++;
  }
 }

 cout<<"indovina quante volte è uscito uno tirando 10 dadi"<<endl;
 cin>>n;

 if(n==counter){
  cout<<"ESATTO, hai indovinato, è uscito 1: "<<counter<<" volte"<<endl;
 }else{
  cout<<"SBAGLIATO, in realtà, è uscito 1: "<<counter<<" volte"<<endl;
 }
 
 return 0;
}

int tira_dado (){
 int numero= rand()%6+1;
 return numero;
}


 