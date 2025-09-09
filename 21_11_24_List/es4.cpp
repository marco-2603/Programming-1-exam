//PILA BASE INPUT FILE ESTERNO, ESCLUTE TUTTI I NON PRIMI
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
void distruggiRIC(nodo *testa);
void primizzaLista(nodo *&testa);
nodo * rimuovi_nodo(nodo *testa);
void rimuovi_first(nodo * &testa);
bool isPrime(int num) {
  if (num < 1) {
    return false;
  }
  for (int i = 2; i <= sqrt(num); ++i) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;

}

int main(int argc, char * argv[]){
 if (argc!=2) { //controllo l'input da cmd
  cerr << "ERRORE, input previsto: ./a.out <filename_in>"<<endl;
  return 0;
 }
 nodo *testa=crealista(argv[1]);
 cout<<"stampo la lista"<<endl;
 stampalista(testa);

 cout<<"stampo la lista dopo aver tolto i non primi"<<endl;
 primizzaLista(testa);
 stampalista(testa);
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

void distruggiRIC(nodo *testa){
 if(testa==NULL){
  return;
 }else {
   distruggiRIC(testa->next);//arrvo alla base della pila e comincio a smontare
   delete testa; 
 }
}

void primizzaLista(nodo *&testa){
 while(!isPrime(testa->val)){
  cout<<"il nodo attuale ha il numero ["<<testa->val<<"] e NON E PRIMO"<<endl;
  rimuovi_first(testa); //controllo se la testa e prima e in caso la elimino
 }
 cout<<"il nodo attuale E PRIMO E ha il numero ["<<testa->val<<"]"<<endl;
 nodo* y = testa->next;
 nodo* x = testa; //creo una copia di testa da mandare avanti perchè è passata per rif
 while (y!=NULL ) {//finche non arrivo alla fine
  if(!isPrime(y->val)){
   cout<<"il nodo prox ha il numero ["<<y->val<<"] e NON E PRIMO"<<endl;
   delete rimuovi_nodo(x); //se non è primo cancello il nodo dopo x (y)
   y=x->next;//riassegno y perchè la avevo cancellata
  }else {
   cout<<"il nodo prox E PRIMO E ha il numero ["<<y->val<<"]"<<endl;
   x=y; //sposto avanti x e y di 1 nodo
   y=y->next;
  }
 }
 cout<<"PRIMIZZATA LA LISTA"<<endl<<endl;
}

nodo * rimuovi_nodo(nodo *testa){
 nodo *prox = testa->next;
 testa->next=prox->next; //prima collego la testa
 prox->next=NULL; //poi scollego prox
 return prox; //e cancello prox
}

void rimuovi_first(nodo * &testa){
 nodo *first= testa;
 if(testa!=NULL){
  testa=testa->next; //sposto la testa
  delete first; //cancello la vecchia testa
 }
}