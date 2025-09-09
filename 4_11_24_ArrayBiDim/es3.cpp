//SOMMA TRIANGOLO SUPERIORE MATRICE
#include <iostream>
#include <cstdlib>
using namespace std;

const int DIM =4;

void inizializza(int a[][DIM]);
void stampa(const int a[][DIM]);
int somma (const int a[][DIM]);

int main(){
 srand(time(NULL));

 int a[DIM][DIM];

 inizializza(a);
 cout<<"la matrice base è: "<<endl;
 stampa(a);
 cout<<endl<<"la somma del triangolo superiore è: "<< somma(a)<<endl;

 return 0;
}

void inizializza(int a[][DIM]){
 for(int i =0;i<DIM;i++){
  for(int j=0;j<DIM;j++){
   a[i][j]=rand()%10;
  }
 }
}

void stampa(const int a[][DIM]){
 for(int i =0;i<DIM;i++){
  for(int j=0;j<DIM;j++){
   cout<<a[i][j]<<" ";
  }
  cout<<endl;
 }
}

int somma(const int a[][DIM]){
 int conta=0;
 for(int i =0;i<DIM;i++){
  for(int j=0;j<DIM;j++){
   if(j>=i){
    conta+=a[i][j];
   }
  }
 }
 return conta;
}
