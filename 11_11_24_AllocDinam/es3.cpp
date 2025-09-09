// ARRAY DINAMICO, SORTING, LETTURA DA FILE
using namespace std;
#include <iostream>
#include <cstdlib>
#include <fstream>

void sort(float temp[],int lenght);

int main(int argc, char* argv[]){
 fstream myin;
 //CONTROLLO CHE L'INPUT DA CMDLINE SIA CORRETTO
 if (argc!=4) {
  cerr << "ERRORE, input previsto: <./a.out> <filename_in> <N> <M>"<<endl;
  return 0;
 }
 //APRO IL FILE E CONTROLLO CHE NON VADA IN FAIL
 myin.open(argv[1],ios::in);
 if (myin.fail()) {
  cerr << "Il file " << argv[1] << " non esiste\n";
  return 0;
 }
 //DICHIARO LE VARIABILI DA USARE
 int DIM=atoi(argv[2]); //numero di elementi che voglio che siano stampati
 int lenght=atoi(argv[3]);//massimo numero di valori registrati nel file
 float *temperature= new float [lenght]; //dichiaro l'array dinamico di size M
 char tmp[256]; //variabile temporanea dove salvare i valori della temperatura
 //RIEMPO L'ARRAY DINAMICO CON I VALORI DELLE TEMP
 for(int i=0;myin>>tmp;i++){
  temperature[i]=atof(tmp); 
 }
 //ORA ORDINO L'ARRAY
 sort(temperature,lenght);
 //STAMPO LE PRIME DIM TEMPERATURE
 cout<<"le prime ["<<DIM<<"] temperature piu alte sono: "<<endl;
 for(int i=0;i<DIM;i++){
  cout<<temperature[i]<<" ";
 }
 cout<<endl;
 //CHIUDO IL FILE E DEALLOCO LA VARIABILE
 myin.close();
 delete[] temperature;

 return 0;
}

void sort(float temp[],int lenght){ //bubble sort basico senza miglioramenti
 for(int i=0;i<lenght-1;i++){
  for(int j=0;j<lenght-1;j++){
   if (temp[j] < temp[j + 1]){
    float a = temp[j];
    temp[j] = temp[j + 1];
    temp[j + 1] = a;
   }
  }
 }
}
