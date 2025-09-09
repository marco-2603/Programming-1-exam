//MATRICE TRASPOSTA
#include <iostream>
#include <cstdlib>
using namespace std;

const int RIGHE = 4;
const int COLONNE = 4;

void inizializza(int a[][COLONNE]);
void stampa(const int a[][COLONNE]);
void trasposta (const int a[][COLONNE], int b[][COLONNE]);

int main(){
 srand(time(NULL));

 int a[RIGHE][COLONNE],b[RIGHE][COLONNE];

 inizializza(a);
 cout<<"la matrice base è: "<<endl;
 stampa(a);
 trasposta(a,b);
 cout<<endl<<"la sua trasposta è: "<<endl;
 stampa(b);


 return 0;
}

void inizializza(int a[][COLONNE]){
 for(int i =0;i<RIGHE;i++){
  for(int j=0;j<COLONNE;j++){
   a[i][j]=rand()%10;
  }
 }
}

void stampa(const int a[][COLONNE]){
 for(int i =0;i<RIGHE;i++){
  for(int j=0;j<COLONNE;j++){
   cout<<a[i][j]<<" ";
  }
  cout<<endl;
 }
}

void trasposta(const int a[][COLONNE],int b[][COLONNE]){
 for(int i =0;i<RIGHE;i++){
  for(int j=0;j<COLONNE;j++){
   b[i][j]=a[j][i];
  }
 }
}
