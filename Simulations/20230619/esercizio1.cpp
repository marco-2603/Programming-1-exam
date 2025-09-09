//SHIFTING PAROLA E RICERCA OCCORRENZE IN FILE DI TESTO
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;


// è possibile definire funzioni di supporto


int main(int argc, char * argv []) {
  fstream myin;

 if (argc!=2) {
  cerr << "ERRORE, input previsto: ./a.out <filename_in>"<<endl;
  return 0;
 }

 myin.open(argv[1],ios::in);
 if (myin.fail()) {
  cerr << "Il file " << argv[1] << " non esiste\n";
  return 0;
 }

    char parola[256];
    int shift;
    cout<<"inserisci una sequenza di caratteri e un numero intero"<<endl;
    cin>>parola>>shift;
    int dim=strlen(parola);

    //tolower
    for(int i=0;i<dim;i++){
        if(parola[i]>='A'&&parola[i]<='Z'){
            parola[i]=parola[i]+('a' - 'A');
        }
    }

    cout<<"la parola ora è: "<<parola<<" e la dim: "<<dim<<endl;

    //SHIFTING
    char temp;
    shift%=dim;
    for(int k=0;k<shift;k++){
        temp=parola[0];
        parola[0]=parola[dim-1];
        for(int i=dim-1;i>1-1;i--){
            parola[i]=parola[i-1];
        }
        parola[1]=temp;
    }

    cout<<"la parola ora è: "<<parola<<" e la dim: "<<dim<<endl;

    //CONTAGGIO OCCORRENZE
    int occorrenze=0;
    while(!myin.eof()){
        myin.get(temp);
        if(temp==parola[0]){
            bool trova=true;
            for(int i=1;i<dim;i++){
                myin.get(temp);
                if(temp!=parola[i]){
                    trova=false;
                }
            }
            if(trova==true){
                occorrenze++;
            }
        }
    }

    cout<<"il numero di occorrenze trovate nel file è: "<<occorrenze<<endl;


 myin.close();
  return 0;

}
