#include <iostream>
#include <climits>

using namespace std;

int massimo (int n1,int n2=INT_MIN, int n3=INT_MIN, int n4=INT_MIN, int n5=INT_MIN);
int max (int n1, int n2);

int main (){
 int n1,n2,n3,n4,n5;
 cout<<"inserisci da uno a cinque interi, inserire 0 se non si vuole fermarsi"<<endl;
 cin>>n1,n2,n3,n4,n5;
 cout<<"il massimo è "<<massimo(n1,n2,n3,n4,n5)<<endl;
 return 0;
}

int massimo (int n1, int n2, int n3, int n4, int n5){
 int massimo;
 massimo=max(n1,n2);
 massimo=max(n2,n3);
 massimo=max(n3,n4);
 massimo=max(n4,n5);
 return massimo;
}

int max(int n1, int n2){
 int massimo;
 if(n1<n2){
  massimo=n2;
 }else massimo=n1;
 return massimo;
}

 