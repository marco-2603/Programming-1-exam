//PILA BASE INPUT FILE ESTERNO, STAMPA, DISTRUGGI ITER E RICOR, STAMPA INV RICORSIVA E ITER
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct nodo;
typedef nodo *lista;

struct nodo{
 int val;
 nodo *next;
}; 

nodo* crealista(char *myin);
void stampalista(nodo *testa);
void distruggilista(nodo *testa);
void distruggiRIC(nodo *testa);
void stampaListaInvertita(nodo *testa);
void stampaListaInvertitaIter(nodo *testa);

int main(int argc, char * argv[]){
 if (argc!=2) { //controllo l'input da cmd
  cerr << "ERRORE, input previsto: ./a.out <filename_in>"<<endl;
  return 0;
 }
 nodo *testa=crealista(argv[1]);
 cout<<"stampo la lista"<<endl;
 stampalista(testa);
 cout<<"stampo la lista INVERTITA"<<endl; 
 stampaListaInvertitaIter(testa);
 distruggiRIC(testa);

 return 0;
}

nodo* crealista(char *file){
 fstream myin;
 myin.open(file,ios::in);//apro il file
 if (myin.fail()) { //controllo che non vada in fail
 cerr << "Il file " << file << " non esiste\n";
 return NULL;
 }

 lista testa=NULL; //inizializzo la testa
 int val;
 while(myin>>val){ //finche ci sono valori nel file crea nodi
  nodo *newNodo=new nodo;
  newNodo->val=val; //crea nuovo nodo
  newNodo->next=testa; //collego il nuovo nodo al corrente (s)
  testa=newNodo; //aggiorna il corrente al nuovo nodo appena creato
 }

 myin.close();
 return testa;
}

void stampalista(nodo *testa){
 nodo* corrente = testa; //collega corrente al nodo in testa
 while (corrente != NULL) {
  cout << corrente->val << " "; //stampa l'ultimo inserito
  corrente = corrente->next; //passa a quello precedente
  cout << endl;
 }
 cout << endl;
}

void distruggilista(nodo *testa){
 nodo *succ; 
 if(testa!=NULL){
  do{
   succ=testa->next;
   delete testa;
   testa=succ;
  }while(testa!=NULL);
 }
}

void distruggiRIC(nodo *testa){
 if(testa==NULL){
  return;
 }else {
   distruggiRIC(testa->next);
   delete testa;
 }
}

void stampaListaInvertita(nodo *testa){
  nodo* corrente = testa; //collega corrente al nodo in testa
  if(corrente==NULL){
   return;
  }else{
   stampaListaInvertita(corrente->next); //vado alla fine della pila
   cout << corrente->val << " "; //stampo 
   cout << endl;
  }
}

void stampaListaInvertitaIter(nodo *testa){
 nodo *tmp;
 nodo *corrente = testa; //collega corrente al nodo in testa
 while(corrente->next!=NULL){
  corrente=corrente->next;
 } 
 tmp=corrente;//sposto tmp al penultimo
 cout<<corrente->val<<endl; 
 while(corrente!=testa){ //se corrente non si è mosso ho finito
  corrente=testa;//restarta corrente
  while(corrente->next!=tmp){ //finchè non sono arrivato a quello prima del tmp vado avanti
  corrente=corrente->next;
  }
  tmp=corrente; //sposto il tmp
  cout<<corrente->val<<endl; //stampo
 }
}