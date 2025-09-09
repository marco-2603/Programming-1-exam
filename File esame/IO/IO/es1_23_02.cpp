//SHIFTING VERSO SINISTRA DELLA PAROLA LASCIANDO INVARIATE TESTA E CODA, TOLOWER
// E RISCRIVI IN FILE OUTPUT TESTO SHIFTATO
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
    }

    int shift;
    cout<<"inserire il valore di shifting"<<endl;
    cin>>shift;

    char parola[256];
    int start,end,nowShift;
    while(myin>>parola){
        nowShift=shift;
        int dim=strlen(parola);
        start=0; 
        end=dim-1;
        if(!(parola[0]>='a'&&parola[0]<='z')&&!(parola[0]>='A'&&parola[0]<='Z')){
            start++;
            //cout<<endl<<"ORA AUMENTO LO START: "<<parola[dim-1]<<endl;
        }
        if(!(parola[dim-1]>='a'&&parola[dim-1]<='z')&&!(parola[dim-1]>='A'&&parola[dim-1]<='Z')){
            end--;
            //cout<<endl<<"ORA AUMENTO LA FINE perchè è: "<<parola[dim-1]<<endl;
        }
        char temp;
        nowShift%=dim;
        //cout<<endl<<"valore di shift è: "<<nowShift<<endl;
        for (int s = 0; s < nowShift; s++){
            temp=parola[start];
            for (int i = start; i < end; i++){
                parola[i]=parola[i+1];
            }
            parola[end]=temp;
        }
        for (int i = 0; i < dim; i++){
            if(parola[i]>='A'&&parola[i]<='Z'){
                parola[i]=parola[i]+('a' - 'A'); //tolower
            }
        }
        
        cout<<parola<<" ";
    }

    cout<<endl;

    return 0;
}
