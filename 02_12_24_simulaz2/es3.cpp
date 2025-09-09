#include <iostream>
#include <cstdlib>
using namespace std;

void init(int *a,int dim);

int main(){
 srand(time(NULL));
 int pdim=3;
 int tdim=20;
 int pattern[pdim];
 int testo[tdim];
 cout<<endl<<"pattern è: ";
 init(pattern,pdim);
 cout<<endl<<"testo è: ";
 init(testo, tdim);
 cout<<endl;
 bool ris;
 for(int i=0;!ris&&i<tdim-pdim;i++){
  if(testo[i]==pattern[0]){
   ris=true;
   for(int j=0;j<pdim;j++){
    if(testo[i+j]!=pattern[j]){
     ris=false;
    }
   }
  }
 }
 if(ris){
  cout<<"ESISTE il pattern in testo"<<endl;
 }else{
  cout<<"pattern NON è in testo"<<endl;
 }
}

void init(int *a,int dim){
 for(int i=0;i<dim;i++){
  a[i]=rand()%10;
  cout<<"["<<a[i]<<"] ";
 }
}