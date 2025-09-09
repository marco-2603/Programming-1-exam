#include <iostream>
#include <cstdlib>
using namespace std;

void riempi(int arr[]);
void stampa(int arr[]);
void inserimento(int arr[], int x, int indice);

int main(){
 srand(time(NULL));
 int arr[10];
 int x, indice;
 cout<<"ora viene creato l'array"<<endl;
 riempi(arr);
 cout<<"l'array è: "<<endl;
 stampa(arr);
 cout<<endl;
 cout<<"ora inserire un numero x e un indice i dove inserire il numero nell'array"<<endl;
 cin>>x>>indice;
 while(indice<0||indice>9){
  cout<<"ERRORE, numero indice inserito non valido, reinserirlo"<<endl;
  cin>>indice;
 }
 cout<<"l'array con il numero inserito e le posizioni traslate è:"<<endl;
 inserimento(arr,x,indice);
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

void inserimento(int arr[],int x,int indice){
 for(int i=9;i>=0;i--){
  if(indice<i){
   arr[i]=arr[i-1];
  }else{
   arr[indice]=x;
  }
 }
 for(int i=0;i<10;i++){
  cout<<arr[i]<<"  ";
 }
 cout<<endl;
}