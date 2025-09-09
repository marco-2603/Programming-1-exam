// Esse3++ (database)
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

struct Studente{
 char nome[31];
 char cognome[31];
 int matricola;
 float media;
};

void stampa_studente(Studente *s){
 cout<<"i dati dello studente sono:"<<endl;
 cout<<"nome: "<<s->nome<<endl;
 cout<<"cognome: "<<s->cognome<<endl;
 cout<<"matricola: "<<s->matricola<<endl;
 cout<<"media: "<<s->media<<endl<<endl;
}

Studente *genera_studente(char nome[], char cognome[], int matricola, float media){
 Studente *s=new Studente;
 s->matricola=matricola;
 s->media=media;
 strcpy(s->nome,nome);
 strcpy(s->cognome,cognome);
 return s;

}

void riempi_database(Studente **database, char file[], int dim){
 cout<<"ENTRO NEL RIEMPI DATABASE"<<endl;
 fstream myin;
 myin.open(file,ios::in);
 if (myin.fail()) { //controllo che il file apra correttamente
  cerr << "Il file " << file << " non esiste\n";
  return;
 } else{
  int indice=0;
  char nome[31], cognome[31];
  int matricola;
  float media;
  while(indice<dim){
   myin>>nome>>cognome>>matricola>>media; //prendo i dati dello studente [indice]
   database[indice]=genera_studente(nome,cognome,matricola,media); // genero lo studente
   indice++;
  }
 }
 return;
}

int main(int argc, char * argv[]){
 char nome[31], cognome[31];
 int matricola;
 float media;
 fstream myin;

 if (argc!=3) { //controllo che l'input da cmdline sia corretto
  cerr << "ERRORE, input previsto: ./a.out <filename_in> <dim>"<<endl;
  return 0;
 }
 int dim=atoi(argv[2]);//inizializzo dim

 Studente **database= new Studente*[dim]; //alloco la memoria per il database

 riempi_database(database,argv[1],dim); //lo riempo
 for(int i=0;i<dim;i++){
 stampa_studente(database[i]); //stampo tutti gli studenti del database studente
 }

 for(int i=0;i<dim;i++){ //dealloco prima tutti gli studenti singolarmente
  delete database[i];
 }
 delete[] database; //poi il daytabase

 return 0;
}