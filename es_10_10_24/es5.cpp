#include <iostream>
#include <cstdlib>
using namespace std;

int tira_dado ();

int main (){
 srand(time(NULL));
 int attaccante, difensore;

 attaccante=tira_dado();
 difensore=tira_dado();

 if(attaccante>difensore){
  cout<<"vince l'attaccante con: "<<attaccante<<" contro: "<<difensore<<endl;
 }else if(difensore>attaccante){
  cout<<"vince il difensore con: "<<difensore<<" contro: "<<attaccante<<endl;
 }else if(attaccante==difensore){
  cout<<"pareggio con: "<<attaccante<<endl;
 }
 return 0;
}

int tira_dado (){
 int numero= rand()%6+1;
 return numero;
}


 