#include <iostream>
using namespace std;

int main (){
 int a,primo=0;
  cout<<"inserisci un numero per controllare se è primo "<<endl;
 cin>>a;

 for(int i=1;i<a;i++){
  if(a%i==0){
   primo++;
  }
 }
 if(primo==1){
  cout<<"il numero è primo"<<endl;
 }else {
  cout<<"il numero non è primo"<<endl;
 }

 return 0;
}
