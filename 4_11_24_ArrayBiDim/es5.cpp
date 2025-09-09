//SABBIE MOBILI / SWAMP
#include <iostream>
#include <cstdlib>
using namespace std;

const int DIM =4;

void inizializza(int a[][DIM],int min, int max);
void stampa(const int a[][DIM]);
void attraversa(const int a[][DIM]);

int main(){
 srand(time(NULL));

 int a[DIM][DIM]={{1,0,0,1},{1,0,0,0},{0,1,0,0},{0,0,1,1}};

 //inizializza(a, 0, 1);
 cout<<"la matrice base è: "<<endl;
 stampa(a);
 attraversa(a);

 return 0;
}

void inizializza(int a[][DIM], int min, int max){
 for(int i =0;i<DIM;i++){
  for(int j=0;j<DIM;j++){
   a[i][j]=rand() % (max+1-min) + min;
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

void attraversa(const int a[][DIM]){
 int i=0,j=0;
 for(;i<DIM;i++){
  if(a[i][j+1]==1){

  }else if(i!=0&&a[i+1][j+1]==1){

  }else if(i!=(DIM-1)&&a[i-1][j+1]==1){

  }
 }
}