#include <iostream>
using namespace std;

int main (){
 int a,b;
 //inserimento:
 cout<<"scegli due interi tra 0 e 127"<<endl;
 cin>>a;
 cin>>b;

 if(a>b||a<0||b>127){
  //goto inserimento;
  cout<<"ERRORE";
  return 0;
 }

 for(int i=a;i<=b;i++){
  cout<<char(i)<<endl;
 }

 return 0;
}
