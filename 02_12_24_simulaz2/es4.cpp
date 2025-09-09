#include <iostream>
#include <cstdlib>
using namespace std;

void hexFill(int *arr,int dim, int i=0);
void stampa(int *arr, int dim,int i=0);

int main(){
 int dim;
 cout<<"inserire la dim"<<endl;
 cin>>dim;

 int *arr=new int [dim];
 hexFill(arr,dim);
 stampa(arr,dim);

 delete[] arr;
}

void hexFill(int *arr,int dim,int i){
 if(i>=dim){
  return;
 }else{
  arr[i]=i*(2*i-1);
  hexFill(arr,dim,i+1);
 }
}

void stampa(int *arr, int dim,int i){
 if(i>=dim){
  cout<<endl;
 }else {
  cout<<"["<<arr[i]<<"] ";
  stampa(arr,dim,i+1);
 }
}