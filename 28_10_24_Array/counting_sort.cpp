
#include <iostream>
#include <cstdlib>
using namespace std;

void inizializza_array(int arr[], int dim);
void stampa_array(int arr[], int dim);
int massimo(const int arr[], int dim);
void counting_sort(int arr[], int dim);


int main (){
 int dim=10;
 int arr[dim];
 srand(time(NULL));

 inizializza_array(arr,dim);
 stampa_array(arr,dim);
 counting_sort(arr,dim);
 cout<<"l'array sortato è: "<<endl;
 stampa_array(arr,dim);

 return 0;
}

void inizializza_array(int arr[], int dim){
 for(int i=0;i<dim;i++){
  arr[i]=rand()%101;
 }
}

void stampa_array(int arr[], int dim){
  for(int i=0;i<dim;i++){
  cout<<arr[i]<<"  ";
 }
 cout<<endl;
}

void counting_sort(int arr[], int dim){
 int mass= massimo(arr,dim);
 int conta[mass+1];
 for(int i=0;i<mass+1;i++){
  conta[i]=0;
 }
 for(int i=0;i<dim;i++){
  for(int j=0;j<mass+1;j++){
   if(arr[i]==j){
    conta[j]++;
    break;
   }
  }
 }
 int somma=0;
 for(int i=0;i<mass+1;i++){
  somma+=conta[i];
  conta[i]=somma;
 }
 int array_out[dim];
 for(int i=0;i<dim;i++){
  conta[arr[i]]--;
  array_out[conta[arr[i]]]=arr[i];
 }
 for(int i=0;i<dim;i++){
  arr[i]=array_out[i];
 }

}

int massimo(const int arr[], int dim){
 int mass=arr[0];
 for(int i=1;i<dim;i++){ 
  if(arr[i]>mass){
   mass=arr[i];
  }
 }
 return mass;
}
