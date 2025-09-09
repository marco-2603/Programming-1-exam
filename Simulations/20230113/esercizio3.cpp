#include <iostream>
#include "pila.h"

using namespace std;

int * collidiAsteroidi(int asteroidi[], int numeroAsteroidi, int & numeroAsteroidiRimasti);

int main() {
    
    // Potete modificare l'array di asteroidi (e la sua
    // dimensione) per testare la vostra soluzione
    int asteroidi [] = {-6, 10, 5, 8, -9};
    int numeroAsteroidi = 5;


    int numeroAsteroidiRimasti;
    int * asteroidiRimasti = collidiAsteroidi(asteroidi, numeroAsteroidi, numeroAsteroidiRimasti);


    // La stampa dell'array dinamico degli
    // asteroidi rimasti avviene nel main
    for (int i = 0; i < numeroAsteroidiRimasti ; i++) {
        cout << asteroidiRimasti[i] << " ";
    }
    cout << endl;

    // La deallocazione dell'array dinamico 
    // degli asteroidi rimasti avviene nel main
    delete[] asteroidiRimasti;
}


// Implementare la funzione sottostante come da consegna:
// - ritornare un'array di interi allocato dinamicamente che 
//   contenga lo stato degli asteroidi dopo tutte le collisioni
// - assegnare a 'numeroAsteroidiRimasti' il numero di elementi 
//   nell'array ritornato
void scontro(int a1, int a2,int &rimasti){
    if(abs(a1)==abs(a2)){
        //scompaiono entrambi
        cout<<"si annullano"<<endl;
        rimasti-=2;
    }else if(abs(a1)>abs(a2)){
        cout<<"rimetto "<<a1<<endl;
        push(a1);
        cout<<"dentro a scontro la pila è:"<<endl;
        stampaPila();
        rimasti--;
    }else {
        cout<<"rimetto "<<a2<<endl;
        push(a2);
        cout<<"dentro a scontro la pila è:"<<endl;
        stampaPila();
        rimasti--;
    }
}

void collidi(int &rimasti,bool &collisione){
    collisione=true;
    int prev,cur;
    while(collisione&&(top(prev)&&pop()&&!vuota())){//se c'è stata una collisione e ci sono almeno 2 elementi
        collisione=false;
        top(cur);
        pop();
        cout<<"faccio un confronto tra "<<prev <<" e "<<cur<<endl;
        if(prev>0&&cur<0){
            cout<<"collisione"<<endl;
            scontro(prev,cur,rimasti);
            collisione=true; 
        }
        if(collisione){
            //collidi(rimasti);
            cout<<"ora ho colliso collisione="<<collisione<<" la situazione è:"<<endl;
            stampaPila();  
            return;
        }else{
            push(cur);
            collidi(rimasti,collisione);
            push(prev);
            cout<<"ora che sono tornato a prima collisione="<<collisione<<" e la situazione è:"<<endl;
            stampaPila();
        }
    }
    return;
}

int * collidiAsteroidi(int asteroidi[], int numeroAsteroidi, int & numeroAsteroidiRimasti) {
    //init pila
    init();
    for (int i = numeroAsteroidi-1; i>=0; i--){
        push(asteroidi[i]);
    }
    numeroAsteroidiRimasti=numeroAsteroidi;

    stampaPila();

    //while (c'è stato uno scontro)
    //ricorsivamente continua a poppare e vedere se prev e cur si scontrano,
    //se si scontrano ripeti
    bool collisione=true;
    collidi(numeroAsteroidiRimasti,collisione);

    stampaPila();

    //crea con il contenuto della pila il nuovo array dinamico dei rimasti
    int * arr=new int[numeroAsteroidiRimasti];
    for(int i=0;i<numeroAsteroidiRimasti;i++){
        top(arr[i]);
        pop();
    }
    
    //deinit pila
    deinit();
    //return array
    return arr;
}
