// Esse3++ (ricerca)
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

int cerca_matricola(Studente ** database, int findMatricola, int dim){
 int matr;
 for(int i=0;i<dim;i++){
  matr=database[i]->matricola;
  if(matr==findMatricola){
   return i;
  }
 }
 return -1;
}

int cerca_nome_e_cognome(Studente ** database, char * findNome, char *findCognome, int dim){
 char checkNome[31],checkCognome[31];
 for(int i=0;i<dim;i++){
  strcpy(checkNome,database[i]->nome);
  strcpy(checkCognome,database[i]->cognome);
  if(!(strcmp(checkNome,findNome))&&!(strcmp(checkCognome,findCognome))){
   return i;
  }
 }
 return -1;
}

int studente_top_media(Studente ** database, int dim){
 float med,max=database[0]->media,maxIndex=0;
 for(int i=1;i<dim;i++){
  med=database[i]->media;
  if(max<med){
   maxIndex=i;
  }
 }
 return maxIndex; 
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
 //ricerca studente per matricola
 int find=-1;
 cout<<"inserire un numero di matricola da cercare nel database"<<endl;
 cin>>matricola;
 find=cerca_matricola(database,matricola,dim);
 if(find==-1){
  cout<<"non è stato trovato nessuno studente con quel numero di matricola"<<endl<<endl;
 }else{
  cout<<"ecco i dati dello studente trovato: "<<endl;
  stampa_studente(database[find]);
 }
 //ricerca studente per nome e cognome
 cout<<"inserire il nome e cognome da cercare nel database"<<endl;
 cin>>nome>>cognome;
 find=cerca_nome_e_cognome(database,nome,cognome,dim);
 if(find==-1){
  cout<<"non è stato trovato nessuno studente con quel nome e cognome"<<endl<<endl;
 }else{
  cout<<"ecco i dati dello studente trovato: "<<endl;
  stampa_studente(database[find]);
 }
 //ricerca studente top media
 find=studente_top_media(database,dim);
 cout<<"ecco i dati dello studente con la media piu alta: "<<endl;
 stampa_studente(database[find]);


 for(int i=0;i<dim;i++){ //dealloco prima tutti gli studenti singolarmente
  delete database[i];
 }
 delete[] database; //poi il daytabase

 return 0;
}