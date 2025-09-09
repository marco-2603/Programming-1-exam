#include <iostream>
using namespace std;

void inverti (int num);

int main (){
 int n;
 cout<<"inserisci un numero"<<endl;
 cin>>n;

 inverti(n);
 
 return 0;
}

void inverti (int num){
 while(num!=0){
  cout<<num%10;
  num/=10;
 }
 cout<<endl;
}


 