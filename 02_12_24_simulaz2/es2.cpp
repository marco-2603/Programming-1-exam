#include <iostream>

using namespace std;

bool palindromo(int *a,int dim);
bool palRec(int *a,int primo, int ultimo);

int main(){
 int dim;
 cout<<"inserire la dimensione dell'array (massimo 100)"<<endl;
 cin>>dim;
 if(dim>100){
  cout<<"ERRORE, dimensione massima superata"<<endl;
  return 0;
 }
 int a[dim];
 cout<<"riempire l'array"<<endl;
 for(int i=0;i<dim;i++){
  cin>>a[i];
 }
 bool pal=palindromo(a,dim);
 if(pal){
  cout<<"PALINDROMO"<<endl;
 }else{
  cout<<"non è palindromo"<<endl;
 }
 return 0;
}

bool palindromo(int *a,int dim){
 return palRec(a, 0, dim-1);
}

bool palRec(int *a,int primo,int ultimo){
 bool ris;
 if(primo>ultimo){
  ris=true;
 }else if(a[primo]!=a[ultimo]){
  ris=false;
 }else {
  ris= palRec(a,primo+1,ultimo-1);
 }
 return ris;
}