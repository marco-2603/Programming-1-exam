//FILTRO MEDIO
#include <iostream>
#include <cstdlib>
using namespace std;

const int DIM =10;

void inizializza(int a[][DIM]);
void stampa(const int a[][DIM]);
void stampa2(const double a[][DIM]);
void filtro_medio (const int a[][DIM],double b[][DIM]);
double media (const int a[][DIM], int i, int j);

int main(){
 srand(time(NULL));

 int a[DIM][DIM];
 double b[DIM][DIM];

 inizializza(a);
 cout<<"la matrice base è: "<<endl;
 stampa(a);
 filtro_medio(a,b);
 cout<<endl<<"il filtro medio è: "<<endl;
 stampa2(b);

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

void stampa2(const double a[][DIM]){
 for(int i =0;i<DIM;i++){
  for(int j=0;j<DIM;j++){
   cout<<a[i][j]<<" ";
  }
  cout<<endl;
 }
}

void filtro_medio(const int a[][DIM],double b[][DIM]){
 for(int i =0;i<DIM;i++){
  for(int j=0;j<DIM;j++){
    b[i][j]=media(a, i ,j);
  }
 }
}

double media(const int a[][DIM], int i, int j){
 double somma=0;
 int conta=0;
 if(i>=1){
  somma+=a[i-1][j];
  conta++;
 }
 if(i<=1){
  somma+=a[i+1][j];
  conta++;
 }
 if(j>=1){
  somma+=a[i][j-1];
  conta++;
 }
 if(j<=1){
  somma+=a[i][j+1];
  conta++;
 }

 cout<<"somma ora è: "<<somma<<endl;
 cout<<"conta ora è: "<<conta<<endl<<endl;
 return (double(somma)/double(conta));
}
