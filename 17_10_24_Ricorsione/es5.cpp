//PALINDROMO
#include <iostream>
using namespace std;

int reverse(int n);
void palindromo(int n);

int main (){
 int n;
 cout<<"inserire un numero per controllare se è palindromo "<<endl;
 cin>>n;
 
 palindromo(n);

 return 0;
}

int reverse(int n){
 int inverso=0,digit;
 /*
 while(n!=0){
  digit=n%10;
  inverso=inverso*10+digit;
  n/=10;
  cout<<"inverso: "<<inverso<<endl;
 }
  cout<<"inverso: "<<inverso<<endl;
 */
 if(n==0){
  return 0;
 }
  
  digit=n%10;  
  cout<<"digit: "<<digit<<endl;

  inverso=digit+reverse(n/10)*10;
  cout<<"inverso: "<<inverso<<endl;
  
  

 return inverso;
}

void palindromo(int n){
 int inverso= reverse(n);

 cout<<inverso<<endl;

 if(inverso==n){
  cout<<"il numero è palindromo"<<endl;
 }else{
  cout<<"Il numero NON è palindromo"<<endl;
 }
 return;
}
