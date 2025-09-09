#include <iostream>
using namespace std;

void swap (double * num1,double * num2);

int main (){
 double num1, num2;
 cout<<"inserisci due double"<<endl;
 cin>>num1>>num2;
 swap(&num1,&num2);
 cout<<num1<<endl<<num2<<endl;
 
 return 0;
}

void swap (double * num1,double * num2){
 double scambia=0;
 scambia=*num1;
 *num1=*num2;
 *num2=scambia;
}

 