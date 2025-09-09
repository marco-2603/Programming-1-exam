#include <iostream>
#include <cstdlib>
using namespace std;

void riempi(int arr[]);
void stampa(int arr[]);

int main(){
 srand(time(NULL));
 int arr[10];
 cout<<"ora viene creato l'array"<<endl;
 riempi(arr);
 cout<<"l'array è: "<<endl;
 stampa(arr);
 cout<<endl;
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