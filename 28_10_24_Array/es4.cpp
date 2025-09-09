#include <iostream>
#include <cstdlib>
using namespace std;

void riempi(int arr[]);
void stampa(int arr[]);
void inverti(int arr[]);

int main(){
 srand(time(NULL));
 int arr[10];
 cout<<"ora viene creato l'array"<<endl;
 riempi(arr);
 cout<<"l'array è: "<<endl;
 stampa(arr);
 cout<<endl;
 cout<<"l'array inverso è: "<<endl;
 inverti(arr);
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

void inverti(int arr[]){
 int var;
 for(int i=0;i<5;i++){
  var=arr[i];
  arr[i]=arr[9-i];
  arr[9-i]=var;
 }
 for(int i=0;i<10;i++){
  cout<<arr[i]<<"  ";
 }
}