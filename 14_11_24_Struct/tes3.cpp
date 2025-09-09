//AGENZIA DEL FARMACO DATABASE
 // Esse3++ (database)
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct Farmaco{ //creo la struct farmaco
 int id;
 int numero_molecole;
 int numero_interazioni;
 int numero_test;
 int numero_reazioni;
};

void stampa_farmaco(Farmaco *s){ //stampo il farmaco
 cout<<"ID farmaco: "<<s->id<<endl;
 cout<<"numero molecole: "<<s->numero_molecole<<endl;
 cout<<"numero interazioni: "<<s->numero_interazioni<<endl;
 cout<<"numero test: "<<s->numero_test<<endl;
 cout<<"numero reazioni avverse: "<<s->numero_reazioni<<endl<<endl;
}

Farmaco *genera_farmaco(int id,int numero_molecole,int numero_interazioni,int numero_test,int numero_reazioni){
 Farmaco *s=new Farmaco; //alloco lo spazio
 s->id=id; //assegno ad ogni valore il suo corrispondente
 s->numero_molecole=numero_molecole;
 s->numero_interazioni=numero_interazioni;
 s->numero_test=numero_test;
 s->numero_reazioni=numero_reazioni;
 return s;
}

void riempi_database(Farmaco **database, char file[], int &dim){
 fstream myin;
 myin.open(file,ios::in);
 if (myin.fail()) { //controllo che il file apra correttamente
  cerr << "Il file " << file << " non esiste\n";
  return;
 } else{
  int indice=0;
  int id, numero_molecole, numero_interazioni, numero_test, numero_reazioni;
  while(myin>>id>>numero_molecole>>numero_interazioni>>numero_test>>numero_reazioni){
    //prendo i dati dei farmaci [indice] finchè ce ne sono
   database[indice]=genera_farmaco(id, numero_molecole, numero_interazioni, numero_test, numero_reazioni); // genero il farmaco
   indice++;
   dim++;
  }
 }
 return;
}

int top_avverse(Farmaco ** database, int dim){
 int avv,max=database[0]->numero_reazioni,maxIndex=0;
 for(int i=1;i<dim;i++){
  avv=database[i]->numero_reazioni;
  if(max<avv){
   maxIndex=i;
   max=avv;
  }
 }
 return maxIndex; 
}

int top_pericolo(Farmaco ** database, int dim){
 int dang,max=(database[0]->numero_reazioni)/(database[0]->numero_test),maxIndex=0;
 for(int i=1;i<dim;i++){
  dang=(database[0]->numero_reazioni)/(database[0]->numero_test);
  if(max<dang){
   maxIndex=i;
   max=dang;
  }
 }
 return maxIndex; 
}

int top_molecole(Farmaco ** database, int dim){
 int mol,max=database[0]->numero_molecole,maxIndex=0;
 for(int i=1;i<dim;i++){
  mol=database[i]->numero_molecole;
  if(max<mol){
   maxIndex=i;
   max=mol;
  }
 }
 return maxIndex; 
}

void top_media_iterazioni(Farmaco ** database, int dim){
 float tot=0;
 for(int i=1;i<dim;i++){
  tot+=database[i]->numero_interazioni;
 }
 float media=tot/dim;
 for(int i=1;i<dim;i++){
  if(database[i]->numero_interazioni>media){
   cout<<"un farmaco con il numero di interazioni sopra la media è: "<<endl;
   stampa_farmaco(database[i]);
  }
 }
}


int main(int argc, char * argv[]){
 //dichiaro i dati dei farmaci
 int id, numero_molecole, numero_interazioni, numero_test, numero_reazioni;
 int dim=0; // inizializzo il contantore di dim del db
 fstream myin;

 if (argc!=2) { //controllo che l'input da cmdline sia corretto
  cerr << "ERRORE, input previsto: ./a.out <filename_in>"<<endl;
  return 0;
 }

 myin.open(argv[1],ios::in);
 if (myin.fail()) { //controllo che il file apra correttamente
  cerr << "Il file " << argv[1] << " non esiste\n";
  return 0;
 } else{
  int indice=0;
  int id, numero_molecole, numero_interazioni, numero_test, numero_reazioni;
  while(myin>>id>>numero_molecole>>numero_interazioni>>numero_test>>numero_reazioni){
   dim++; //conto quanti elementi ci sono nel file
  }
 }

 Farmaco **database= new Farmaco*[dim]; //alloco la memoria per il database

 myin.close();
 myin.open(argv[1],ios::in);

 int indice=0; 
 while(myin>>id>>numero_molecole>>numero_interazioni>>numero_test>>numero_reazioni){
   //prendo i dati dei farmaci [indice] finchè ce ne sono
  database[indice]=genera_farmaco(id, numero_molecole, numero_interazioni, numero_test, numero_reazioni); // genero il farmaco
  indice++;
 } //riempo il db

 cout<<endl<<"il numero totale di farmaci è: "<<dim<<endl<<endl;

 cout<<"il farmaco con il maggior numero di reazioni avverse è:"<<endl;
 stampa_farmaco(database[top_avverse(database,dim)]);
 cout<<endl;

 cout<<"il farmaco piu PERICOLOSO è:"<<endl;
 stampa_farmaco(database[top_pericolo(database,dim)]);
 cout<<endl;

 cout<<"il farmaco con il maggior numero di molecole è:"<<endl;
 stampa_farmaco(database[top_molecole(database,dim)]);
 cout<<endl;

 cout<<"i farmaci con numero di interazioni sopra la media sono:"<<endl;
 top_media_iterazioni(database,dim);
 cout<<endl;
 

 for(int i=0;i<dim;i++){ //dealloco prima tutti gli studenti singolarmente
  delete database[i];
 }
 delete[] database; //poi il daytabase
 myin.close();

 return 0;
}