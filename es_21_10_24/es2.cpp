#include <iostream>
using namespace std;

double mcd(int m,int n);

int main (){
 int m,n;
 cout<<"inserire due interi"<<endl;
 cin>>m>>n;
 cout<<mcd(m,n)<<endl;
 
 return 0;
}

double mcd(int m,int n){
 int risp=0;
 if(n==0){
  risp=m;
 }else{
  risp=mcd(n,m%n);
 }
 
 return risp;
}
