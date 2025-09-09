#include <iostream>
#include <cstdlib>
using namespace std;

void riempi(int arr[]);
void stampa(int arr[]);
double media(int arr[]);
int max(int arr[]);
int min(int arr[]);

int main(){
 srand(time(NULL));
 int arr[10];
 cout<<"ora viene creato l'array"<<endl;
 riempi(arr);
 cout<<"l'array è: "<<endl;
 stampa(arr);
 cout<<endl;
 cout<<"la media dei numeri dell'array è: "<<media(arr)<<endl;
 cout<<"il massimo è: "<<max(arr)<<endl;
 cout<<"il minimo è: "<<min(arr)<<endl;
}

void riempi(int arr[]){
 for(int i=0;i<10;i++){
  arr[i]=rand()%10;
 }
}

void stampa(int arr[]){
 for(int i=0;i<10;i++){
  cout<<arr[i]<<"  ";
 }
}

double media(int arr[]){
 double med=0;
 for (int i=0;i<10;i++){
  med+=arr[i];
 }
 med/=10;
 return med;
}

int max(int arr[]){
 int mass=0;
 for (int i=0;i<10;i++){
  if(mass<arr[i]){
   mass=arr[i];
  }
 }
 return mass;
}

int min(int arr[]){
 int mini=10;
 for (int i=0;i<10;i++){
  if(mini>arr[i]){
   mini=arr[i];
  }
 }
 return mini; 
}