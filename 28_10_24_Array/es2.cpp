#include <iostream>
#include <cstdlib>
using namespace std;

void riempi(int arr1[], int mass);
void stampa(int arr2[], int mass);
int confornto(int arr1[],int arr2[]);

int main(){
 srand(time(NULL));
 int arr1[10],arr2[10];
 int mass;
 cout<<"scegliere il range dei possibili valori dell'array"<<endl;
 cout<<"massimo"<<endl;
 cin>>mass;
 mass++;
 riempi(arr1,mass);
 cout<<"l'array è: "<<endl;
 stampa(arr2,mass);
 cout<<endl;
 cout<<"i numeri uguali allo stesso inidice sono: "<<confornto(arr1,arr2)<<endl;

 return 0;
}

void riempi(int arr1[],int mass){
 for(int i=0;i<10;i++){
  arr1[i]=rand()%mass;
 }
}

void stampa(int arr2[],int mass){
 for(int i=0;i<10;i++){
  arr2[i]=rand()%mass;
  cout<<arr2[i]<<"  ";
 }
}

int confornto(int arr1[],int arr2[]){
 int count=0;
 for(int i=0;i<10;i++){
  if(arr1[i]==arr2[i]){
   count++;
  }
 }
 return count;
}