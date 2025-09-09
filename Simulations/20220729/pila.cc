#include <iostream>
#include <cstring>
#include "pila.h"
using namespace std;

static int *p;
static int DIM;
static int indexP1;
static int indexP2;

// inizializza P1 e P2 con un'array o una lista 
// doppiamente concatenata con dimensione massima 
// 'dim'. Di conseguenza, la somma del numero di 
// elementi in P1 e P2 può essere al massimo uguale 
// a 'dim';
void init(int dim){
    p=new int[dim];
    DIM=dim;
    indexP1=-1;
    indexP2=dim;
}

// inserisci l'elemento 'valore' in P1
bool pushP1(int valore){
    if(indexP1+1!=indexP2){
        indexP1++;
        p[indexP1]=valore;
        return true;
    }else{
        cout<<"dim massima raggiunta"<<endl;
        return false;
    }
}

// inserisci l'elemento 'valore' in P2
bool pushP2(int valore){
    if(indexP1+1!=indexP2){
        indexP2--;
        p[indexP2]=valore;
        return true;
    }else{
        cout<<"dim massima raggiunta"<<endl;
        return false;
    }
}

// assegna al parametro il valore del primo 
// elemento di P1, se presente
bool topP1(int& num){
    if(indexP1>=0){
        num=p[indexP1];
        return true;
    }else{
        return false;
    }
}

// assegna al parametro il valore del primo 
// elemento di P2, se presente
bool topP2(int& num){
    if(indexP2<DIM){
        num=p[indexP2];
        return true;
    }else{
        return false;
    }
}

// rimuovi il primo elemento di P1, se presente
bool popP1(){
    if(indexP1>=0){
        p[indexP1]=0;
        indexP1--;
        return true;
    }else{
        return false;
    }
}

// rimuovi il primo elemento di P2, se presente
bool popP2(){
    if(indexP2<DIM){
        p[indexP2]=0;
        indexP2++;
        return true;
    }else{
        return false;
    }
}

// de-inizializza la pila e dealloca la memoria dinamica
void deinit(){
    delete [] p;
}

// stampa a video gli elementi di P1 e P2
void print(){
    if(indexP1==-1){
        cout<<"la pila 1 è vuota"<<endl;
    }else {
        cout<<"la pila 1 è: ";
        for (int i = 0; i < indexP1+1; i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }

    if(indexP2==DIM){
        cout<<"la pila 2 è vuota"<<endl;
    }else {
        cout<<"la pila 2 è: ";
        for (int i = DIM-1; i < indexP2-1; i--){
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
}
