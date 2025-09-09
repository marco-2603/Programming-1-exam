//STAMPA MATRICE
#include <iostream>
#include <cstdlib>
using namespace std;

const int RIGHE = 4;
const int COLONNE = 4;

void inizializza(int a[][COLONNE]);
void stampa(const int a[][COLONNE]);

//stesse funzioni ma con i puntatori
void inizializza_punt(int *a);
void stampa_punt(const int *a);

int main(){
 srand(time(NULL));

 int a[RIGHE][COLONNE];

 cout<<"la matrice con i due for è: "<<endl;
 inizializza(a);
 stampa(a);

 cout<<endl<<"la matrice con i puntatori è: "<<endl;
 inizializza_punt(*a);
 stampa_punt(*a);

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

void inizializza_punt(int* a){
 for(int i=0;i<(RIGHE*COLONNE);i++){
  *(a+i)=rand()%10;
 }
}

void stampa_punt(const int* a){
 cout<<"scritto male"<<endl;
 for(int i=0;i<(RIGHE*COLONNE);i++){
  cout<<*(a+i)<<" ";
  if(i>0 && i%COLONNE==0){cout <<endl;}
 }
 cout<<endl<<"scritto giusto"<<endl;
 for(int i =0;i<RIGHE;i++){
  for(int j=0;j<COLONNE;j++){
   cout<<*(a*COLONNE+j)<<" ";
  }
  cout<<endl;
 }

}