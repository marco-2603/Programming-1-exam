//CONTO LUNGHEZZA DELLE RIGHE, E STAMPO SU FILE LA LUNGHEZZA, POI SCRIVO PER INTERO LA RIGA
//PIU LUNGA
#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


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

    char riga[256];
    int max=0,maxindex=0;
    for(int i=0;myin.getline(riga,255);i++){
        //cout<<riga<<endl;
        int len;
        for (len=0;riga[len]!='\0';len++){}
        myout<<len<<endl;
        if(len>max){
            max=len;
            maxindex=i;
        }
    }
    //chiudo e riapro il file in
    myin.close();
    myin.open(argv[1],ios::in);
    if (myin.fail()) {
        cerr << "Il file " << argv[1] << " non esiste\n";
        return 0;
    }
    //ora stampo la riga piu lunga
    for (int i = 0; i <= maxindex; i++){
        myin.getline(riga,255);
    }
    myout<<riga<<" "<<max<<endl;
    


    myin.close();
    myout.close();
    return 0;
}
