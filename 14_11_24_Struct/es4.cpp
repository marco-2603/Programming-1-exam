// Esse3++ (COMPLETO)
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

void riempi_database(Studente **database, char file[], int &index){
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
  while(myin>>nome>>cognome>>matricola>>media){//prendo i dati dello studente [indice]
   database[indice]=genera_studente(nome,cognome,matricola,media); // genero lo studente
   indice++;
   index++;
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
 int dim=100,index=0;//inizializzo dim e l'index
 int find=-1; //variabile usata nella ricerca

 Studente **database= new Studente*[dim]; //alloco la memoria per il database
 char s;
 do{ //legenda
  cout<<endl<<"scegliere l'azione da compiere:"<<endl;
  cout<<"aggiungere un utente (a)"<<endl;
  cout<<"cercare un utente per matricola (m)"<<endl;
  cout<<"cercare un utente per nome e cognome (n)"<<endl;
  cout<<"ritornare l'utente con la media ponderata piu alta (p)"<<endl;
  cout<<"aggiungere studenti da file esterno (f)"<<endl;
  cout<<"esci (e)"<<endl;
  cin>>s;
 
 switch(s){
  case 'a': //inserisci studente
  cout<<"inserire i dati dello studente: <nome> <cognome> <matricola> <media>"<<endl;
  cin>>nome>>cognome>>matricola>>media;
  database[index]=genera_studente(nome,cognome,matricola,media);
  index++;
  break;
  case 'm': //ricerca studente per matricola
  cout<<"inserire un numero di matricola da cercare nel database"<<endl;
  cin>>matricola;
  find=cerca_matricola(database,matricola,dim);
  if(find==-1){
   cout<<"non è stato trovato nessuno studente con quel numero di matricola"<<endl<<endl;
  }else{
   cout<<"ecco i dati dello studente trovato: "<<endl;
   stampa_studente(database[find]);
  } 
  break;
  case 'n': //ricerca nome cognome
  cout<<"inserire il nome e cognome da cercare nel database"<<endl;
  cin>>nome>>cognome;
  find=cerca_nome_e_cognome(database,nome,cognome,index);
  if(find==-1){
   cout<<"non è stato trovato nessuno studente con quel nome e cognome"<<endl<<endl;
  }else{
   cout<<"ecco i dati dello studente trovato: "<<endl;
   stampa_studente(database[find]);
  }
  break;
  case 'p': //media piu alta
  find=studente_top_media(database,dim);
  cout<<"ecco i dati dello studente con la media piu alta: "<<endl;
  stampa_studente(database[find]);
  break;
  case 'f': //importa file
  char file[41];
  cout<<"inserire il nome del file da importare"<<endl;
  cin>>file;
  riempi_database(database,file,index);
  break;

  case 'e':
  break;

  default: cout<<"scelta errata, ripetere"<<endl;
  break;

 }
 }while (s!='e');

 
 cout<<"STAMPO TUTTI GLI STUDENTI:"<<endl<<endl;
 for(int i=0;i<index;i++){
 cout<<endl<<"stampo studente ["<<i<<"]: "<<endl;
 stampa_studente(database[i]); //stampo tutti gli studenti del database studente
 }

 for(int i=0;i<dim;i++){ //dealloco prima tutti gli studenti singolarmente
  delete database[i];
 }
 delete[] database; //poi il daytabase

 return 0;
}