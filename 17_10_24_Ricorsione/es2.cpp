#include <iostream>
using namespace std;

long int fact(int n);

int main (){
 int num;
 cout<<"inserire un numero di cui calcolarne il fattoriale"<<endl;
 cin>>num;
 
 cout<<"il fattoriale è: "<<fact(num)<<endl;

 return 0;
}

long int fact(int n){
 int fatt;
 if(n<0){
  cout<<"ERRORE, inserito numero negativo"<<endl;
  fatt=0;
 }else if(n==1||n==0){
  fatt=1;
 }else{
  fatt=n*fact(n-1);
 }
 return fatt;
}
