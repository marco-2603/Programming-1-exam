//SABBIE MOBILI / SWAMP
#include <iostream>
#include <cstdlib>
using namespace std;

const int DIM =10;

void inizializza(int a[][DIM],int min, int max);
void stampa(const int a[][DIM]);
int contaisole(const int a[][DIM]);
int isola(const int a[][DIM],int i, int j);


int main(){
 srand(time(NULL));

 int a[DIM][DIM]; //={{1,0,1,0},{0,0,0,1},{0,1,0,0},{1,0,0,1}};

 inizializza(a, 0, 1);
 cout<<"la matrice base è: "<<endl;
 stampa(a);
 cout<<"il numero delle isole è: "<<contaisole(a)<<endl;

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

int contaisole(const int a[][DIM]){ //does the check for every position of the matrix
 int isole=0;
 cout<<endl;
 for(int i=0;i<DIM;i++){
  for(int j=0;j<DIM;j++){
   //cout<<"è isola a["<<i<<"]["<<j<<"]? "<<isola(a, i, j)<<endl; //this is just to see if it works
   if(isola(a, i, j)){
    isole++;
   }
  }
 }
 return isole;
}

int isola(const int a[][DIM], int i, int j){ //checks that it has only 0 around
 if(i<DIM-1&&a[i+1][j]==1)return false;
 if(i>0&&a[i-1][j]==1)return false;
 if(j<DIM-1&&a[i][j+1]==1)return false;
 if(j>0&&a[i][j-1]==1)return false;
 if(i<DIM-1&&j<DIM-1&&a[i+1][j+1]==1)return false;
 if(i<DIM-1&&j>0&&a[i+1][j-1]==1)return false;
 if(i>0&&j<DIM-1&&a[i-1][j+1]==1)return false;
 if(i>0&&j>0&&a[i-1][j-1]==1)return false;
 return true;
}