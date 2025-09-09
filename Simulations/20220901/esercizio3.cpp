//decodifica numero, da una stringa DDDD IIII usa una pila per riscriverla con D maggiore
//I minore, usa la pila per riscrivere il numero in base alle relazioni tra essi
#include <iostream>
#include <string.h> // definisce la funzione "int strlen (const char * array);"
#include <math.h>   // definisce la funzione "int pow (base, esponente);"
#include "pila.h"   // fare riferimento al file "pila.h" per le funzioni esposte

using namespace std;

int decodificaNumero(char numeroCodificato []);

int main() { 
    int dimensioneMassima = 9;
    char numeroCodificato [dimensioneMassima];
    cout << "Inserisci l'array: ";
    cin >> numeroCodificato;
    int decodifica = decodificaNumero(numeroCodificato);
    cout << "Decodifica: " << decodifica << endl;
}

int decodificaNumero(char numeroCodificato []) {
    init();
    int numero = 0;
    int lenCodifica = strlen(numeroCodificato);
    int esponente = lenCodifica;
    cout<<"lenCodifica è: "<<lenCodifica<<endl;
    for (int i = 0; i <= lenCodifica; i++){
        push(i+1);
        if(numeroCodificato[i]=='I'||i==lenCodifica){
            while(!vuota()){
                int a;
                top(a);
                numero+=a*pow(10,esponente);
                esponente--;
                pop();
            }
        }
    }

    deinit();
    return numero;
}
