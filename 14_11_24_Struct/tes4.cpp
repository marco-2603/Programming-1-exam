//ALBERO GENEALOGICO STRUCT BASE
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct persona{
 char nome[31];
 char madre[31];
 char padre[31]; 
 int figli; 
 int nipoti;
};

persona *genera_persona(char nome[], char madre[], char padre[]){
 persona *s=new persona; //alloco lo spazio
 //assegno ad ogni valore il suo corrispondente
 strcpy(s->nome,nome);
 strcpy(s->madre,madre);
 strcpy(s->padre,padre);
 return s;
}

void stampa_persona(persona *s){ //stampo il farmaco
 cout<<"Il nome della persona è: "<<s->nome<<endl;
 cout<<"La MADRE è: "<<s->madre<<endl;
 cout<<"Il PADRE è: "<<s->padre<<endl;
 cout<<"il numero di FIGLI è: "<<s->figli<<endl;
  cout<<"il numero di NIPOTI è: "<<s->nipoti<<endl;
}


int main(int argc, char * argv[]){
 fstream myin;
 char nome[31],padre[31],madre[31];
 int dim=0; //setto a 0 la dim dell'array di persone

 if (argc!=2) { //controllo che l'input da cmdline sia corretto
  cerr << "ERRORE, input previsto: ./a.out <filename_in>"<<endl;
  return 0;
 }

 myin.open(argv[1],ios::in);
 if (myin.fail()) { //controllo che il file apra correttamente
  cerr << "Il file " << argv[1] << " non esiste\n";
  return 0;
 } else{
  int c;
  myin>>c;
  dim=c;
 }
 cout<<"la DIM è di: ["<<dim<<"] \n"; 

 persona **persone= new persona*[dim]; //alloco la memoria per la lista di pesone

 for(int i=0;myin>>nome>>madre>>padre; i++){
   //prendo i dati dei farmaci [indice] finchè ce ne sono
  persone[i]=genera_persona(nome, madre, padre); // genero il farmaco
 } //riempo il db

 //GENITORE CON PIU FIGLI
 for(int i=0;i<dim;i++){
  for(int j=0;j<dim;j++){
   if(!strcmp(persone[i]->nome,persone[j]->padre)||!strcmp(persone[i]->nome,persone[j]->madre)){
    persone[i]->figli+=1;
   }
  }
 }
 int maxfigli=persone[0]->figli;
 int maxindex=0;
 for(int i=0;i<dim;i++){ 
  if(maxfigli<persone[i]->figli){
   maxfigli=persone[i]->figli;
   maxindex=i;
  }
 }


 cout<<"il genitore con piu figli è: "<<persone[maxindex]->nome<<" con "<<maxfigli<<" figli"<<endl;
 
 //NONNO CON PIU NIPOTI
 for(int i=0;i<dim;i++){
  for(int j=0;j<dim;j++){
   for(int k=0;k<dim;k++){
    if(!strcmp(persone[i]->nome,persone[j]->padre)||!strcmp(persone[i]->nome,persone[j]->madre)){
     if(!strcmp(persone[j]->nome,persone[k]->padre)||!strcmp(persone[j]->nome,persone[k]->madre)){
      persone[i]->nipoti+=1;
    }
   }
  }
 }
 }
 int maxnipoti=persone[0]->nipoti;
 int maxindex=0;
 for(int i=0;i<dim;i++){ 
  if(maxfigli<persone[i]->nipoti){
   maxfigli=persone[i]->nipoti;
   maxindex=i;
  }
 }

 for(int i=0;i<dim;i++){
  stampa_persona(persone[i]);
  cout<<endl;
 }

 cout<<"il nonno con piu nipoti è: "<<persone[maxindex]->nome<<" con "<<maxnipoti<<" figli"<<endl;

 return 0;
}
