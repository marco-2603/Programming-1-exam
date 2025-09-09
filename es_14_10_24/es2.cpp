#include <iostream>
using namespace std;

int divisione (int num1,int num2, int &rest);

int main (){
 int num1, num2, rest=0;
 cout<<"inserisci due interi"<<endl;
 cin>>num1>>num2;
 cout<<divisione(num1,num2,rest)<<endl<<rest<<endl;
 
 return 0;
}

int divisione (int num1,int num2, int & rest){
 int quoz;
 quoz=num1/num2;
 rest=num1%num2;
 return quoz;
}

 