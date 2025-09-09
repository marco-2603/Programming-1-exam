#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int tira_dado ();

int main (){
 srand(time(NULL));
 int a_max, a_min, d_max, d_min;

 a_max=max(tira_dado(),tira_dado());
 a_min=min(tira_dado(),tira_dado());
 d_max=max(tira_dado(),tira_dado());
 d_min=min(tira_dado(),tira_dado());
 
 if(a_max>d_max){
  cout<<"vince max l'attaccante con: "<<a_max<<" contro: "<<d_max<<endl;
 }else if(d_max>a_max){
  cout<<"vince max il difensore con: "<<d_max<<" contro: "<<a_max<<endl;
 }else if(a_max==d_max){
  cout<<"pareggio con: "<<a_max<<endl;
 }

 if(a_min>d_min){
  cout<<"vince min l'attaccante con: "<<a_min<<" contro: "<<d_min<<endl;
 }else if(d_min>a_min){
  cout<<"vince min il difensore con: "<<d_min<<" contro: "<<a_min<<endl;
 }else if(a_min==d_min){
  cout<<"pareggio con: "<<a_min<<endl;
 }

 return 0;
}

int tira_dado (){
 int numero= rand()%6+1;
 return numero;
}


 