#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct dataStruct {
 int *data;
 int size, numData;
};

void ResizeArray(dataStruct *orig, int size);

int main(){
 int dim=10;
 dataStruct *A=new dataStruct; //creo dinamicamente la struttura A
 
 A->size=dim;
 A->numData=0;
 A->data=new int [dim];
 
 for(int i=0;i<5;i++){
  A->data[i]=i+1;
  A->numData++;
 }

 cout<<"l'array iniziale è"<<endl;
 for(int i=0;i<A->numData;i++){
  cout<<"arr ["<<i<<"] = "<<A->data[i]<<endl;
 }
 
 ResizeArray(A,A->numData);
 
 cout<<"l'array dopo il ridimensionamento è"<<endl;
 for(int i=0;i<A->size;i++){
  cout<<"arr ["<<i<<"] = "<<A->data[i]<<endl;
 }
 
 delete[] A->data;
 delete A;
}

void ResizeArray(dataStruct *orig, int size){
 int *copia= new int[size];
 for(int i=0;i<size;i++){
  copia[i]=orig->data[i];
 }
 delete[] orig->data;
 orig->data=copia;
 orig->size=size;
}
