// LEGGI FRASE DA FILE (myin.get(c)), ISOLA LE INIZIALI E GENERA 
// UNA PAROLA RANDOM DA QUELLE LETTTERE 
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int ContaParole(char **pwords);
void GeneraParole(char *pwords[],int n,char password[]);

int main(int argc, char * argv[]){
    srand(time(NULL));
    char text[5000];
    char *pwords[5000];
    for (int i = 0; i < 5000; i++)
    {
        pwords[i]=NULL;
    }

    if (argc!=2) {
        cerr << "ERRORE, input previsto: ./a.out <filename_in>"<<endl;
        return 0;
    }
    
    fstream myin;
    myin.open(argv[1],ios::in);
    if (myin.fail()) {
        cerr << "Il file " << argv[1] << " non esiste\n";
        return 0;
    }
    
    char c;
    int j=0;
    cout<<"frase iniziale: "<<endl;
    for (int i = 0;i<5000&&!myin.eof(); i++)
    {
        myin.get(c);
        text[i]=c;
        cout<<text[i];
        if(c==' '||c=='\n'){//se prima c'è uno spazio o a capo
            myin.get(c);//questa è l'inizio di una parola
            i++;
            text[i]=c;
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                cout<<text[i];
                pwords[j]=&text[i]; //cosi assegno a pwd[j] il puntatore a tex[i]
                j++;
            }
        }
    }
    cout<<endl;

    int npar=ContaParole(pwords);
    cout<<"il numero di parole è: "<<npar<<endl;
    cout<<"Initials: ";
    for (int i = 0; i < npar; i++)
    {
        cout<<*pwords[i];//siccome pwords[] è un array di puntatori mettend * stampo solo il carattere a cui punta
    }
    cout<<endl;

    char password[7];
    GeneraParole(pwords,npar,password);
    cout<<"Generated word: ";
    for (int i = 0; i < 7; i++)
    {
        cout<<password[i];
    }
    cout<<endl;

    myin.close();
    return 0;
}

int ContaParole(char **pwords){
    int i;
    for (i = 0; pwords[i]!=NULL; i++){}
    return i;
}

void GeneraParole(char *pwords[],int n,char password[]){
    for (int i = 0; i < 6; i++)
    {
        password[i]=*pwords[(rand()%n)-1];
    }
    password[6]='\0';
}

// Add your code hereafter