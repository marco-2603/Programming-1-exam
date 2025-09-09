#include <iostream>
#include <cstdlib>
using namespace std;

void hexFill(char *arr,int dim, int i=0);
void stampa(char *arr, int dim,int i=0);
void ruota(char *arr, int dim, int j, int i=0);
void rotazione(char *arr, int dim, int i=0);

int main(){
 srand(time(NULL));
 int n,j;
 cout<<"inserire la dim"<<endl;
 cin>>n;
 cout<<"inserire quanto spostare (j)"<<endl;
 cin>>j;

 char *arr=new char [n];
 hexFill(arr,n);
 cout<<"l'array prima è:"<<endl;
 stampa(arr,n);
 cout<<"l'array DOPO è:"<<endl;
 ruota(arr,n,j);
 stampa(arr,n);
 delete[] arr;
}

void hexFill(char *arr,int dim,int i){
 if(i>=dim){
  return;
 }else{
  arr[i]=rand()%26+65;
  hexFill(arr,dim,i+1);
 }
}

void stampa(char *arr, int dim,int i){
 if(i>=dim){
  cout<<endl;
 }else {
  cout<<"["<<arr[i]<<"] ";
  stampa(arr,dim,i+1);
 }
} 

void ruota(char *arr, int dim, int j,int i){
 if(i<j){
  char k=arr[0];
  rotazione(arr,dim);
  arr[dim-1]=k;
  ruota(arr,dim,j,i+1);
 }
}

void rotazione(char *arr, int dim, int i){
 if(i>=dim-1){
  return;
 }else {
  arr[i]=arr[i+1];
  rotazione(arr,dim,i+1);
 }
}