//LETTURA DEMACS ARRAY BIDIM DINAMICO E OPERAZIONI/CONTROLLI VARIE
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;

void print_clauses(int **arr);

// Insert solution hereafter
int main(int argc, char * argv[]){
 fstream myin;

 if (argc!=2) {
  cerr << "ERRORE, input previsto: ./a.out <filename_in> <filename_out>"<<endl;
  return 0;
 }

 myin.open(argv[1],ios::in);
 if (myin.fail()) {
  cerr << "Il file " << argv[1] << " non esiste\n";
  return 0;
 }

 char p;
 myin>>p;
 char cnf[4];
 myin>>cnf;
 int clausole, nvar;
 myin>>clausole;
 myin>>nvar;
 
 if(p!='p'||strcmp(cnf,"cnf")!=0||clausole<=0||nvar<=0){
  cout<<"ERRORE, file input errato"<<endl;
  myin.close();
  return 0;
 }

 int ** arr=new int *[clausole+1]; //alloco la memo

 bool errore=false;

 arr[clausole]=nullptr;
 int i=0;
 for(i=0;i<clausole&&!errore&&!myin.eof();i++){
  int dim; 
  myin>>dim; //leggi il numero di letterali di questa clausola
  arr[i]=new int[dim+1];
  for(int j=0;j<dim;j++){
   myin>>arr[i][j];
   if(abs(arr[i][j])>nvar||arr[i][j]==0||myin.eof()){
    cout<<"ho incontrato un errore su: "<<arr[i][j]<<endl;
    errore=true;
    break;
   }
  }
  if(!errore){ //se non ci sono errori metto il terminatore
   arr[i][dim]=0;
  }
 }
 { //questo controlla che se il file non è finito allora ci sono problemi
    char c;
    myin >> c;
    if (!myin.eof()) {
        errore = true;
    }
 }

 if(errore||i!=clausole){//controllo che i dati inseriti siano giusti
  cout<<"eof or clause out of bound, or 0 encountered, or more clauses encountered"<<endl;
  for(int i=0;i<clausole;i++)
  return 0;
 }

 myin.close(); //chiudo file
 
 print_clauses(arr);//stampo

 //qua dealloca
 for(int i=0;i<clausole&&arr[i]!=NULL;i++){
  delete [] arr[i];
 }
 delete [] arr;
}

void print_clauses(int **arr){
 int max=arr[0][0];
 int i=0;
 //stampa la matrice di clausole
 for(i=0;arr[i]!=NULL;i++){
  for(int j=0;arr[i][j]!=0;j++){
   if(abs(arr[i][j])>max){
    max=abs(arr[i][j]);
   }
   cout<<arr[i][j]<<" ";
  }
  cout<<"0"<<endl;
 }
 //poi stampa p cnf nclaus nvar
 cout<<"p cnf "<<i<<" "<<max<<endl;
}