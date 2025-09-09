//MATRICE DINAMICA
using namespace std;
#include <iostream>
#include <cstdlib>

int ** generate_matrix(int n, int l);

int main(int argc, char* argv[]){
 srand(time(NULL));
 //CONTROLLO ARGOMENTI IN RIGA DI COMANDO
 if(argc!=2){
 cout<<"Usage: <./a.out> <n> <l>"<<endl;
 return 0;
 }
 //LEGGO GRANDEZZA ARRAY E LO GENERO
 int n, l;
 n=atoi(argv[1]);
 l=atoi(argv[2]);
 int **mat=generate_matrix(n, l);
 //STAMPO LA MATRICE
 for(int i=0;i<n;i++){
  for(int j=0;j<l;j++){
   cout<<mat[i][j]<<" ";
  }
  cout<<endl;
 }
 cout<<endl;
 //DEALLOCO PRIMA RIGA PER RIGA LA MATRICE E NELL'INTEREZZA
 for(int i=0;i<n;i++){
  delete[] mat[i];
 }
 delete[] mat;
 return 0;
}

int ** generate_matrix(int n,int l){
 // ALLOCO LA MEMORIA NECESSARIA PER LA MATRICE
 int ** mat = new int*[n]; 

 for(int i=0;i<n;i++){
  mat[i]=new int [l]; //qua sto creando degli array per ogni riga della mat
 }
 //RIEMPO LA MATRICE
 for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
   mat[i][j]=rand()%100;
  }
 }

 return mat;
}