//ARRAY BIDIMENSIONALE (MATRICE) DINAMICO CREA DISTRUGGI STAMPA
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

void print(int **arr,int dim);

int main(){
 srand(time(NULL));
 int dim=4;

 int ** arr=new int *[dim]; //alloco la memo

 for(int i=0;i<dim;i++){
  arr[i]=new int[dim];
  for(int j=0;j<dim;j++){
   arr[i][j]=rand()%10;
  }
 }

 print(arr,dim);

 //qua dealloca
 for(int i=0;i<dim;i++){
  delete [] arr[i];
 }
 delete [] arr;
}

void print(int **arr,int dim){
 cout<<"la matrice è:"<<endl;
 for(int i=0;i<dim;i++){
  for(int j=0;j<dim;j++){
   cout<<arr[i][j]<<" ";
  }
  cout<<endl;
 }
}