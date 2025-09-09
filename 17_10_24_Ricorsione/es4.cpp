//STAMPA BINARIO
#include <iostream>
using namespace std;

void binario(int n);

int main (){
 int num;
 cout<<"inserire un numero da convertire in binario "<<endl;
 cin>>num;
 
 cout<<"il numero in binario è: "<<endl;
 binario(num);
 cout<<endl;

 return 0;
}

void binario(int n){
 if(n!=0){
  binario(n/2);
 }
 cout<<(n%2);
}
