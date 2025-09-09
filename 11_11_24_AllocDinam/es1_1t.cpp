//ARRAY DINAMICO DALL'UTENTE, FILTER RICORSIVA
using namespace std;
#include <iostream>
#include <cstdlib>

int* filter(int* arr_in, int len_in, int& len_out);
int* filter_rec1(int* arr_in, int len_in, int count, int& len_out);
void filter_rec(int* arr_in, int len_in, int count,int* arr_out, int i);
int lunghezza(int* arr_in, int len_in, int count, int& len_out);

int main(){
 //CREO E RIEMPIO L'ARRAY CON DIME CHIESTA ALL'UTENTE
 int len_in,len_out=0;
 cout<<"inserire la lunghezza dell'array"<<endl;
 cin>>len_in;

 int* arr_in= new int[len_in];

 cout<<"riempi l'array"<<endl;
 for(int i=0;i<len_in;i++){ //riempo l'array
  cin>>arr_in[i];
 }

 cout<<"l'array prima del filtro è"<<endl;
 for(int i=0;i<len_in;i++){ //stampo il primo array
  cout<<arr_in[i]<<" ";
 }
 cout<<endl;

 //funzione ricorsiva
 int count=0;
 len_out=lunghezza(arr_in,len_in,count,len_out); //calcolo la lunghezza
 cout<<"la lunghezza del secondo array è: "<<len_out<<endl;
 int* arr_out= filter_rec1(arr_in,len_in,count,len_out); //chiamo la funzione

 //per farla con quella iterativa:
 //int* arr_out= filter(arr_in,len_in,len_out);
 
 cout<<"l'array dopo il filtro è"<<endl;
 for(int i=0;i<len_out;i++){ //stampo il seconda array
  cout<<arr_out[i]<<" ";
 }
 cout<<endl;

 return 0;
}

/*
prima calcolo len_out poi creo l'array dinamico arr_out[len_out].
poi faccio la stessa cosa che ho fatto per controllare se il valore di i di 
arr_in è valido solo che sto giro se è valido lo metto in arr_out
*/

//filter iterativa
int* filter(int* arr_in, int len_in, int& len_out){
 for(int i=0; i<len_in;i++){ //calcolo la lunghezza del secondo array
  if(arr_in[i]%2==0) len_out++;
 }
 int* arr_out=new int[len_out]; //creo il secondo array con la lunghezza giusta
 int count=0;
 for(int i=0; i<len_in;i++){ //riempo il secondo array con i valori giusti
  if(arr_in[i]%2==0){
   arr_out[count]=arr_in[i];
   count++;
  }
 }
 return arr_out;
}

//wrapper per la funzione filter rec
int* filter_rec1(int* arr_in, int len_in, int count, int& len_out){
 int* arr_out=new int[len_out];
 int i=0;
 filter_rec(arr_in,len_in,count,arr_out,i);
 return arr_out;
}

//riempie il secondo array con i valori corrispondenti
void filter_rec(int* arr_in, int len_in, int count,int* arr_out, int i){
 if(i==len_in){
  return;
 }else if(arr_in[i]%2==0){
  arr_out[count]=arr_in[i];
  filter_rec(arr_in,len_in,count+1,arr_out,i+1);
 }else{
  filter_rec(arr_in,len_in,count,arr_out,i+1);
 }
}

//calcola la lunghezza del secondo array
int lunghezza(int* arr_in, int len_in,int count, int& len_out){
 if(count==len_in){
  return 0;
 }else if(arr_in[count]%2==0){
  return 1+lunghezza(arr_in,len_in,count+1,len_out);
 }else{
  return lunghezza(arr_in,len_in,count+1,len_out);
 }
}