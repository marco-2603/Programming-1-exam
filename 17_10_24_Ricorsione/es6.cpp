//SOMMA DELLE CIFRE
#include <iostream>
using namespace std;

int sumcif(long int n);

int main (){
 long int n;
 cout<<"inserire un numero"<<endl;
 cin>>n;

 cout<<"la somma delle cifre del numero inserito è: "<<sumcif(n)<<endl;

 return 0;
}

int sumcif(long int n){
 int somm=0;
 if(n==0){
  somm=0;
 }else {
  somm=(n%10)+sumcif(n/10);
  cout<<"SOMMA: "<<somm<<endl;
  cout<<"N: "<<n<<endl;
  
 }
 return somm;
}
