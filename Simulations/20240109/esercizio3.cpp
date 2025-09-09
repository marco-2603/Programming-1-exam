#include <iostream>
#include "lista.h"

using namespace std;

const int POS_AL_SECONDO = 2;
const int DIM_COLORI = 4;
const int MAX_BAMBINI = 10;

const char* nomi[18] = {"Marco", "Luca", "Anna", "Sabrina", "Veronica", "Simone", "Mario", "Luigi", "Antonio", "Francesca", "Giovanni", "Letizia", "Lucrezia", "Carolina", "Luca", "Annalisa", "Susanna", "Licia"};
const color colori[DIM_COLORI] = {rosso, verde, blu, giallo};

// Inserire QUI sotto la dichirazione delle funzioni coloraPartecipante e cerca.
nodo * cerca(nodo * l,char v[]);
nodo * coloraPartecipante(nodo * l,int k, int i);
// Inserire QUI sopra la dichirazione delle funzioni coloraPartecipante e cerca.

int main() {
    lista cerchio = NULL;
    
    unsigned int seed = time(NULL);
    // Commentare la riga sotto per non avere sempre lo stesso seed
    seed = 1703945587;
    std::cout << "Seed: " << seed << std::endl;
    srand(seed);
  

    int numero_bambini = rand() % MAX_BAMBINI + 2;
    for (int i = 0; i < numero_bambini; i++) {
        char* nome = (char*)nomi[rand() % 18];
        if (cerca(cerchio, nome) == NULL) {
            insert_in(cerchio, nome, 0);
        } else {
            i--;
        }
    }

    cout << "Ci sono " << size(cerchio) << " bambini nella lista." << endl;
    print(cerchio);

    int i = 0;
    int durata;
    bool finished = false;

    while (!empty(cerchio) && !finished) {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Giro numero " << ++i << endl;
        
        cout << "La canzone durerà per " << (durata = rand() % 60 + 10) << " secondi." << endl;

        int sedia_rimossa = rand() % size(cerchio);
        cout << "Fermo il bambino alla sedia numero " << sedia_rimossa << "." << endl;

        lista eliminato = coloraPartecipante(cerchio, durata, sedia_rimossa);

        if (eliminato != NULL) {
            cout << eliminato->nome << " ha ricevuto il colore " << eliminato->colore << endl;
        } else {
            cout << "Tutti i bambini hanno un colore. Ho finito." << endl;
            finished = true;
        }
        print(cerchio);
    }

    cout << "-------------------------------------------------------------" << endl;
    cout << "Tutti i bambini hanno un colore. Ho finito." << endl;

    return 0;
}

// Inserire QUI la definizione delle funzioni coloraPartecipante e cerca.

nodo * cerca(nodo * l,char v[]){
 if(empty(l)){
  return NULL;
 }
 nodo* p = l;
 do{
  if(!strcmp(l->nome,v)){
   return l;
  }
  p=p->next;
 }while(p!=l);
 return NULL;
}

nodo * coloraPartecipante(nodo * l,int k, int i){
 if(empty(l)){
  cout<<"ERRORE, il cerchio è vuoto"<<endl;
  return NULL;
 }

 nodo* p = l;
 for(int j=0;j<(k*POS_AL_SECONDO)+i-1;j++){//scorro lista in base al tempo (una volta in meno per fermarmi al prec)
  p=p->next;
 }
 nodo * prec=p;
 p=p->next;//scorro l'ultima volta

 color colore;
 int contatore=0;

 while(p->colore!=-1&&contatore<size(l)){
  cout<<p->nome<<" ha gia un colore, skippo"<<endl;
  p=p->next;
  prec=prec->next;
  contatore++;
 }

 if(contatore==size(l)){//nessuno eliminato
  return NULL; 
 }

 color coloreNew;
 coloreNew=color(rand() % 4);
 cout<<"Colore: "<<coloreNew<<endl;
 while(prec->colore==coloreNew||p->next->colore==coloreNew){
 if(p->next==prec&&prec->colore!=coloreNew){//controllo se la lista ha 2 o meno elem
  p->colore=coloreNew;
  return p;
 }
 cout<<"controllo se "<<prec->nome<<" e se "<<p->next->nome<<" hanno lo stesso colore ("<<coloreNew<<") di "<<p->nome<<endl;
 coloreNew=color(rand() % 4);
 }
 cout<<"scelto il colore "<<coloreNew<<" per il partecipante "<<p->nome<<endl;
 p->colore=coloreNew; 
 
 return p;
}