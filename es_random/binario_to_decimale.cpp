#include <iostream>
using namespace std;

int main (){
 int bin,dec=0,pot;
 cout<<"inserisci un numero binario"<<endl;
 cin>>bin;

 for(int i=0;bin!=0;i++){
  pot=1;
  for(int j=i;j>0;j--){
   pot*=2;
  }
  dec+=(pot*(bin%10));
  bin/=10;
 }

 cout<<"il numero inserito in decimale è: "<<dec<<endl;
 return 0;
}
