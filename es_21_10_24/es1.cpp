#include <iostream>
using namespace std;

double funz(int m,int n);
void ripeti(bool &check);

int m,n;

int main (){
 bool check=1;
 cout<<"inserire base ed esponente"<<endl;
 cin>>m>>n;
 cout<<funz(m,n)<<endl;

 ripeti(check);
 
 return 0;
}

double funz(int m,int n){
 double risp;
 if(n<0){
  risp=1.0/m*funz(m,n+1);
 }else if(n==0){
  risp=1;
 }else {
  risp=m*funz(m,n-1);
 }
 
 return risp;
}

void ripeti(bool &check){
 cout<<"se si vuole ripetere il programma inserire 1 altrimenti 0 per fermarsi"<<endl;
 cin>>check;
 if(check==true){
  cout<<"inserire base ed esponente"<<endl;
  cin>>m>>n;
  cout<<funz(m,n)<<endl;  
  ripeti (check);
 }
}