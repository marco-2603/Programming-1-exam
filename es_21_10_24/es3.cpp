#include <iostream>
using namespace std;

long funz(int m,int n,long res);
void ripeti(bool &check);

int m,n;
long res=1.0;

int main (){
 bool check=1;
 cout<<"inserire base ed esponente"<<endl;
 cin>>m>>n;
 cout<<funz(m,n,res)<<endl;

 ripeti(check);
 
 return 0;
}

long funz(int m,int n,long res){
 if(n<0){
  funz(m,n+1,res/m);
 }else if(n==0){
  res=res;
 }else {
  funz(m,n-1,res*m);
 }
 
 return res;
}

void ripeti(bool &check){
 cout<<"se si vuole ripetere il programma inserire 1 altrimenti 0 per fermarsi"<<endl;
 cin>>check;
 if(check==true){
  cout<<"inserire base ed esponente"<<endl;
  cin>>m>>n;
  cout<<funz(m,n,res)<<endl;  
  ripeti (check);
 }
}