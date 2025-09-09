//LISTA BASE DINAMICA DOPPIAMENTE CONCATENATA PRENDENDO VALORI DA UN ARRAY
#include <iostream>
#include <cstdlib>

struct nodo {
    int valore;
    nodo* nodoPrecedente;
    nodo* nodoSuccessivo;
};
typedef nodo* lista;

using namespace std;


void inizializza (int arrayDiInteri [], int dimensioneArray);
void stampaLista (lista nodoCorrente);

// Inserire qui la dichiarazione di "creaLista" e "rimuoviNodiAlternati"
nodo * creaLista(int arr[], int dim);
void deallocaLista(nodo * &nodoIniziale);

int main() { 

    // Non modificare la funzione "main". Si può invece (temporaneamente)
    // modificare la funzione "inizializza" per dare dei valori specifici
    // agli elementi dell'array "arrayDiInteri" ai fini di debugging.

    int dimensioneArray = 8;
    int arrayDiInteri[dimensioneArray];
    inizializza(arrayDiInteri, dimensioneArray);

    lista nodoIniziale = creaLista(arrayDiInteri, dimensioneArray);

    cout << "Lista iniziale: ";
    stampaLista(nodoIniziale);

    deallocaLista(nodoIniziale);

    return 0;
}

void inizializza (int arrayDiInteri [], int dimensioneArray) {
    srand(time(NULL));

    for (int i = 0 ; i < dimensioneArray ; i++) {
        arrayDiInteri[i] = i % 3;
    }

    int contatore = dimensioneArray;
    while (contatore > 1) {
       int indice = rand() % contatore;
       contatore--;
       int temp = arrayDiInteri[contatore];
       arrayDiInteri[contatore] = arrayDiInteri[indice];
       arrayDiInteri[indice] = temp;
    }
}

void stampaLista(nodo* nodoCorrente) {
    while (nodoCorrente != NULL) {
        cout << nodoCorrente->valore << " ";
        nodoCorrente = nodoCorrente->nodoSuccessivo;
    }
    cout << endl;
}


nodo * creaLista(int arr[], int dim){
    if (dim == 0) {
        return nullptr; // Se l'array è vuoto, restituisce nullptr
    }

    nodo* testa = new nodo;
    testa->valore=arr[0]; // Crea il primo nodo
    nodo* corrente = testa; // Nodo corrente per l'inserimento successivo

    for (int i = 1; i < dim; ++i) {
        nodo* nuovoNodo = new nodo;
        testa->valore=arr[0]; // Crea un nuovo nodo con il valore dell'array[i]
        corrente->nodoSuccessivo = nuovoNodo;   // Collega il nodo corrente al nuovo nodo
        nuovoNodo->nodoPrecedente = corrente;   // Collega il nuovo nodo al nodo corrente
        corrente = nuovoNodo; // Sposta il puntatore corrente al nuovo nodo
    }

    return testa; // Restituisce il puntatore al primo nodo della lista
}

void deallocaLista(nodo * &nodoIniziale){
    lista corrente=nodoIniziale;
    while(corrente!=nullptr){
        lista temp=corrente;
        corrente = corrente->nodoSuccessivo;
        delete temp;
    }
    nodoIniziale = nullptr;
}