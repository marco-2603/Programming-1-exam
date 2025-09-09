#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
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
        return 1;
    }

    char find[256];
    cout<<"inserisci una sequenza di caratteri da ricercare nel file"<<endl;
    cin>>find;
    cout<<"le parole trovate sono:"<<endl;

    while(!myin.eof()){
        char parola[256];
        myin>>parola;
        bool match=true;
        if(strlen(parola)!=strlen(find)){
            match=false;
        }
        for (int i = 0; i < strlen(find); i++){
           if(!(find[i]=='*'&&((parola[i]>='a'&&parola[i]<='z')||(parola[i]>='A'&&parola[i]<='Z')))
           &&!(find[i]==parola[i])){
            match=false;
            break;
           }
        }
        if(match==true){
            cout<<parola<<endl;
        }
    }


  return 0;
}
