//LETTURA DATI DA DUE FILE, TORNA LA PERCENT DI VOLTE IN CUI I VALORI DEL PRIMO SUPERANO
//I VALORI DEL SECONDO
#include <iostream>
#include <fstream>

// Inserire qui sotto la soluzione all'esercizio
using namespace std;

float percentuale(int super, int dimtemp);

int main(int argc, char * argv[]){
 fstream temp1,temp2;

 if (argc!=3) {
  cerr << "ERRORE, input previsto: ./a.out <filename_in> <filename_out>"<<endl;
  return 0;
 }

 temp1.open(argv[1],ios::in);
 if (temp1.fail()) {
  cerr << "Il file " << argv[1] << " non esiste\n";
  return 0;
 }

 temp2.open(argv[2],ios::in);
 if (temp2.fail()) {
  cerr << "Il file " << argv[2] << " non e' scrivibile\n";
  temp1.close();
  return 0;
 }

 int dimtemp=0, super=0;

 int t1,t2;
 
 while(!temp1.eof()){
  temp1>>t1;
  temp2>>t2;
  if(t1>t2){
   super++;
  }
  dimtemp++;
 }

 if(dimtemp>0){
 float perc=percentuale(super,dimtemp);
 cout<<"La percentuale di misurazioni in cui la temperatura del motore1 ha superato quella del motore2 e’ del "<<perc<<"%"<<endl;
 }else {
  cout<<"Il numero delle misurazioni e’ uguale a zero, per cui non posso calcolare la percentuale"<<endl;
 }

 temp1.close();
 temp2.close();
 return 0;
}

float percentuale(int super, int dimtemp){
 float perc;
 perc=float(super)*100/float(dimtemp);
 return perc;
}