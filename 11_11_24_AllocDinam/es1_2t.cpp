//MATRICE DINAMICA TRASPOSTA
using namespace std;
#include <iostream>
#include <cstdlib>

int ** generate_matrix(int n);
int** trasposta(int** mat, int n);

int main(int argc, char* argv[]){
 srand(time(NULL));
 //CONTROLLO ARGOMENTI IN RIGA DI COMANDO
 if(argc!=2){
 cout<<"Usage: <./a.out> <n>"<<endl;
 return 0;
 }
 //LEGGO GRANDEZZA ARRAY E LO GENERO
 int n;
 n=atoi(argv[1]);
 int **mat=generate_matrix(n);
 //STAMPO LA MATRICE
 for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
   cout<<mat[i][j]<<" ";
  }
  cout<<endl;
 }
 cout<<endl;
 //CALCOLO LA TRASPOSTA
 int** mat_trasp=trasposta(mat,n);
 //STAMPO LA MATRICE TRASPOSTA
 for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
   cout<<mat_trasp[i][j]<<" ";
  }
  cout<<endl;
 }
 //DEALLOCO PRIMA RIGA PER RIGA LA MATRICE E NELL'INTEREZZA
 for(int i=0;i<n;i++){
  delete[] mat[i];
 }
 delete[] mat;
  for(int i=0;i<n;i++){
  delete[] mat_trasp[i];
 }
 delete[] mat_trasp;
 return 0;
}

int ** generate_matrix(int n){
 // ALLOCO LA MEMORIA NECESSARIA PER LA MATRICE
 int ** mat = new int*[n]; 

 for(int i=0;i<n;i++){
  mat[i]=new int [n]; //qua sto creando degli array per ogni riga della mat
 }
 //RIEMPO LA MATRICE
 for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
   mat[i][j]=rand()%10;
  }
 }

 return mat;
}

int** trasposta(int** mat, int n){
 int ** mat_trasp = new int*[n]; //alloco la memoria
 for(int i=0;i<n;i++){
  mat_trasp[i]=new int [n]; //qua sto creando degli array per ogni riga della mat
 }
 
 //RIEMPO LA MATRICE
 for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
   mat_trasp[i][j]=mat[j][i];
  }
 }

 return mat_trasp;

}