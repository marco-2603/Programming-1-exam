//RICERCA ALL'INTERNO DI UNA FRASE DEI CARATTERI E RISCRIVI LA FRASE CON SOLO I CARATTERI
//CHE CORRISPONDONO ALLA RICHIESTA
#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


int main(int argc, char * argv []) {
    fstream myin;

    if (argc!=2) {
        cerr << "ERRORE, input previsto: ./a.out <filename_in>"<<endl;
        return 0;
    }

    myin.open(argv[1],ios::in);
    if (myin.fail()) {
        cerr << "Il file " << argv[1] << " non esiste\n";
        return 1;
    }

    char find[256];
    cout<<"inserisci una sequenza di caratteri da ricercare nel file"<<endl;
    //cin>>find;
    //QUESTO NON VA PERCHE LO SPAZIO FA FINIRE IL CIN
    cin.getline(find,256); //questo prende anche gli spazi
    cout<<"la frase trovata è:"<<endl;

    char c;
    myin.get(c);
    while(!myin.eof()){
        for (int i = 0;i<strlen(find); i++){
            char q=find[i];
            char Q=q;
            if(q>='a'&&q<='z'){
                Q=q-('a' - 'A');
            }
            if(q>='A'&&q<='Z'){
                Q=q+('a' - 'A');
            }

            if(c==q||c==Q){
                cout<<c;
                break;
            }
        }
        myin.get(c);
    }
    cout<<endl;

    myin.close();   
    return 0;
}
