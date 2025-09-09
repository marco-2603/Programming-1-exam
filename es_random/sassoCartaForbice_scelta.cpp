#include <iostream>
using namespace std;

int main (){
 srand(time(NULL));

 int mode;
 cout<<"scegliere se simulare una partita tra due robot (1), tra robot e giocatore (2) o tra due giocatori (3)"<<endl;
 cin>>mode;
 while(mode<1||mode>3){
  cout<<"ERRORE, selezione sbagliata, rifarla;"<<endl;
  cout<<"scegliere se simulare una partita tra due robot (1), tra robot e giocatore (2) o tra due giocatori (3)"<<endl;
  cin>>mode;  
 }


 return 0;
}
 