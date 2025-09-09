//CODIFICA E DECODIFICA IN BASE 36
#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;

int encode(char * parola);
void decode(int coded, char * parola);

int main(int argc, char * argv []) {
    fstream myin,myout;

    if (argc!=3) {
        cerr << "ERRORE, input previsto: ./a.out <filename_in> <filename_out>"<<endl;
        return 0;
    }

    myin.open(argv[1],ios::in);
    if (myin.fail()) {
        cerr << "Il file " << argv[1] << " non esiste\n";
        return 0;
    }

    myout.open(argv[2],ios::out);
    if (myout.fail()) {
        cerr << "Il file " << argv[2] << " non e' scrivibile\n";
        myin.close();
        return 0;
    }

    char parola[10];
    cout<<"inserire un numero di massimo 7 cifre"<<endl;
    cin>>parola;
    while(strlen(parola)>7){
        cout<<"errore, numero inserito errato, reinserirlo"<<endl;
        cin>>parola;
    }

    int key=atoi(parola);
    cout<<"key= "<<key<<endl;
    while(myin>>parola){
        parola[4]='\0';
        cout<<"parola: "<<parola<<endl;
        //decodifica, da char parola deve diventare un int
        int decoded;
        decoded=encode(parola);
        cout<<"decoded before: "<<decoded<<endl;

        //sommo la chiave alla parola decodificata
        decoded+=key;
        cout<<"decoded after: "<<decoded<<endl,

        //ricodifico la parola 
        decode(decoded,parola);
        myout<<parola<<" ";
        cout<<"parola after: "<<parola<<endl,

        decoded=encode(parola)-key;
        decode(decoded, parola);
        cout<<"parola before: "<<parola<<endl;
        //TEST
    }

    myin.close();
    myout.close();
    return 0;
}

int encode(char * parola){//da base 36 a base 10
    int num,decoded=0;
    for (int i = 0; i < strlen(parola); i++)
    {
        if(parola[i]>='a'){
            num=parola[i]-'a'+10;
            //cout<<"la lettera "<<parola[i]<<" vale "<<num<<endl;
        }else{
            num=parola[i]-'0';
        }
        decoded+=num*pow(36,3-i);
    }
    
    return decoded;
}

void decode(int coded, char * parola){//da base 10 a base 36
    int num,i;
    for(i=0;(coded%36)!=0;i++){
        num=coded%36;

        if(num>=10){
            parola[i]=num-10+'a';
        }else{
            parola[i]=num+'0';
        }

        coded=(coded-num)/36;
    }
    parola[i]='\0';

    //reverse
    char temp;
    for (int j = 0; j < strlen(parola)/2; j++){
        temp=parola[j];
        parola[j]=parola[strlen(parola)-1-j];
        parola[strlen(parola)-1-j]=temp;
    }
    
}
