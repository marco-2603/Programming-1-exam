#include <iostream>
#include <cstdlib>
#include "coda.h"

using namespace std;

int trovaIlVincitore(int n, int k);

int main(int argc, char * argv[]) {

    if (argc != 3) {
        cerr << "Usage: a./out <numeroDiAmici> <numeroDiSalti>" << endl;
        exit(0);
    }

    cout << "Il vincitore e' l'amico numero " << trovaIlVincitore(atoi(argv[1]), atoi(argv[2])) << endl;
}


// Implementare la funzione sottostante come da consegna:
// - 'numeroDiAmici' è il numero di amici, o anche chiamato 'n'
// - 'numeroDiSalti' è il numero di salti, o anche chiamato 'k' 
int trovaIlVincitore(int numeroDiAmici, int numeroDiSalti) {
    //INIT CODA
    init();
    for(int i=1;i<=numeroDiAmici;i++){
        enqueue(i);
    }
    
    //WHILE(i can dequeue ) FAI LA ROBA DI ELIMINARE COI SALTI
    int primo,temp;
    while(first(primo)&&dequeue()&&first(temp)){
        enqueue(primo);
        //cout<<"il numero attuale è: "<<primo<<endl;
        for(int i=0;i<numeroDiSalti-1;i++){
            first(temp);
            dequeue();
            enqueue(temp);
            //cout<<"sto saltando: "<<temp<<endl;
        }
        first(temp);
        dequeue();
        //cout<<"ho tolto il numero: "<<temp<<endl;
    }
    
    deinit();
    return primo;
}
