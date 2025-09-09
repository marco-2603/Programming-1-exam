
#include <iostream>
using namespace std;

int divisione(int dividendo, int divisore);

int main (){
 int n1,n2;
 cout<<"inserire due numeri, dividendo e divisore"<<endl;
 cin>>n1>>n2;
 
 cout<<"la divisione è: "<<divisione(n1,n2)<<endl;

 return 0;
}

int divisione(int dividendo, int divisore){
 int res=0;
 if(dividendo<=divisore){
  cout<<"resto = "<<dividendo<<endl;
  res=0;
 }else {
  dividendo -=divisore;
  res=1+divisione((dividendo-divisore), divisore);
 }
 return res;
}
