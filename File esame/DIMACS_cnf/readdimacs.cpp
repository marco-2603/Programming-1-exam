//PARTENDO DA UN FILE DIMACS E UNA TABELLA DI VERITA DELLE VARIABILI DEVO DARE IL RISULTATO
//CHE DA IL FILE PASSANDOCI LE VARIABILI CON QUEI VALORI
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(int argc, char ** argv){
    //controllo che l'input sia giusto
    if (argc!=3) {
        cerr << "ERRORE, input previsto: ./a.out <demacs.cnf> <tabella.verita>"<<endl;
        return 0;
    }

    //APRO IL FILE
    fstream dimacs,tabella;
    dimacs.open(argv[1],ios::in);
    if (dimacs.fail()) {
        cerr << "Il file " << argv[1] << " non esiste\n";
        return 0;
    }

    //CONTROLLO INTESTAZIONE FILE DIMACS
    int nclaus, nvar;
    char prefix[100];
    char cnf[100];
    // Read p cnf nclauses nvariables
    dimacs >> prefix >> cnf >> nclaus >> nvar;
    if (strcmp(prefix, "p") != 0 || strcmp(cnf, "cnf") != 0 || 
        nclaus <= 0 || nvar <= 0) {
        std::cerr << "Error reading header of file \"" << argv[1] << "\"" << std::endl;
        dimacs.close();
        tabella.close();
        return 1;
    }

    //APRO LA TABELLA E ASSEGNO I VALORI ALLE VARIABILI
    tabella.open(argv[2],ios::in);
    if (tabella.fail()) {
        cerr << "Il file " << argv[2] << " non esiste\n";
        dimacs.close();
        return 0;
    }

    bool error=false;

    bool *var=new bool [nvar];
    int i,val;
    for (i = 0; tabella>>val; i++){
        if(i<nvar){
            var[i]=val;
        }
    }
    if(i!=nvar){
        error=true;
    }

    char p;
    tabella>>p;
    if(error){ //se non ci sono abbastanza dati o ce ne sono troppi su tabella
        cout<<"ERRORE, file tabella incorretto"<<endl;
        delete [] var;
        dimacs.close();
        tabella.close();
        return 1;
    }


    int n;
    bool mid=true,ris=false;
    //ORA SCORRO IL FILE DIMACS PER CONTROLLARE LA FORMULA DI VERITA
    for (i = 0; dimacs>>n; i++){
        while (n!=0){
            if(n>0){
                ris=ris||var[n-1];
                cout<<"faccio "<<ris<<" OR "<<var[n-1]<<endl;
            }else{
                ris=ris||(!var[abs(n)-1]);
                cout<<"faccio "<<ris<<" OR (qua not)"<<!var[abs(n)-1]<<endl;
            }
            dimacs>>n;
        }
        cout<<"cambio riga e faccio "<<mid<<" AND "<<ris<<endl;
        mid=mid&&ris;
    }

    if(i!=nclaus){//controllo che il file dimacs sia corretto
        cout<<"ERRORE, file dimacs incorretto"<<endl;
        delete [] var;
        dimacs.close();
        tabella.close();
        return 1;
    }

    //stampo il risultato dell'operazione
    if(mid){
        cout<<"il risultato delle operazioni è: TRUE"<<endl;
    }else{
        cout<<"il risultato delle operazioni è: FALSE"<<endl;
    }
    
    //dealloco e chiudo i file
    delete [] var;
    dimacs.close();
    tabella.close();
    return 0;
}