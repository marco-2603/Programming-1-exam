//TRIS
#include <iostream>
#include "es4_tris.h"
using namespace std;

void iniziaGioco(){
 srand(time(NULL));
 char matrice[DIM][DIM];
 inizializzaMatrice(matrice);
 //stampaMatrice(matrice);
 char simboloUtente,simboloComputer;
 cout<<"scegliere se giocare cerchio (o) o croce (x)"<<endl;
 cin>>simboloUtente;
 if(simboloUtente=='o'){
  simboloComputer='x';
 }else if(simboloUtente=='x'){
  simboloComputer='o';
 }else{
  cout<<"ERRORE, INSERITO SIMBOLO ERRATO"<<endl;
  return;
 }



}

void inizializzaMatrice (char matrice[DIM][DIM]){
 for(int i=0;i<DIM;i++){
  for(int j=0;j<DIM;j++){
   matrice[i][j]=' ';
  }
 }
}

void stampaMatrice(const char matrice[DIM][DIM]){
 cout<<"la matrice è: "<<endl;
 for(int i=0;i<DIM;i++){
  for(int j=0;j<DIM;j++){
   cout<<' ';
   cout<<matrice[i][j];
   cout<<' ';
  }
  cout<<endl;
 }
 cout<<endl<<endl;
}

bool gioca(char matrice[DIM][DIM], bool turnoUtente, char 
simboloUtente, char simboloComputer){

}

bool controllaVincita (const char matrice[DIM][DIM], char
simbolo, bool &pareggio){

}

int sceltaComputer(){
 return rand()%9;
}

bool occupato(const char matrice[DIM][DIM], int posizione){
 
 if(matrice[])
}