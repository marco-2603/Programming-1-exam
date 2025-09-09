//MATRICE DINAMICA TRASPOSTA
using namespace std;
#include <iostream>
#include <cstdlib>

int** generate_matrix(int r, int c);
int maxrow(int** mat, int i, int c);

int main(int argc, char* argv[]){
 srand(time(NULL));
 //CONTROLLO ARGOMENTI IN RIGA DI COMANDO
 if(argc!=3){
 cout<<"Usage: <./a.out> <Numb of rows> <Numb of columns> "<<endl;
 return 0;
 }
 //LEGGO GRANDEZZA ARRAY E LO GENERO
 int r,c;
 r=atoi(argv[1]);
 c=atoi(argv[2]);
 int **mat=generate_matrix(r,c);
 //STAMPO LA MATRICE
 for(int i=0;i<r;i++){
  for(int j=0;j<c;j++){
   cout<<mat[i][j]<<" ";
  }
  cout<<endl;
 }
 cout<<endl;
 //CALCOLO IL MASSIMO DI OGNI RIGA E LO STAMPO
 for(int i=0;i<r;i++){
  cout<<"max row "<<i+1<<" ="<<maxrow(mat,i,c)<<endl;
 }
 //DEALLOCO PRIMA RIGA PER RIGA LA MATRICE E POI NELL'INTEREZZA
 for(int i=0;i<r;i++){
  delete[] mat[i];
 }
 delete[] mat;

 return 0;
}

int** generate_matrix(int r, int c){
 // ALLOCO LA MEMORIA NECESSARIA PER LA MATRICE
 int** mat = new int*[r]; 

 for(int i=0;i<r;i++){
  mat[i]=new int [c]; //qua sto creando degli array per ogni riga della mat
 }
 //RIEMPO LA MATRICE
 cout<<"inserire i valori della matrice: "<<endl;
 for(int i=0;i<r;i++){
  for(int j=0;j<c;j++){
   cin>>mat[i][j];
  }
 }

 return mat;
}

int maxrow(int** mat,int i, int c){
 int max=mat[i][0];
 for(int j=1;j<c; j++){
  if(mat[i][j]>max){
   max=mat[i][j];
  }
 }
 return max;
}