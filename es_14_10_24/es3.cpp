#include <iostream>
using namespace std;

void cambio (int &sec,int &min, int &ore);

int main (){
 int sec, min, ore;
 cout<<"inserisci secondi, minuti, ore"<<endl;
 cin>>sec>>min>>ore;
 cambio(sec,min,ore);
 cout<<"la'orario corretto è: "<<sec<<":"<<min<<":"<<ore<<endl;
 
 return 0;
}

void cambio (int &sec,int &min, int &ore){
while(min>=60||sec>=60){
 if(sec>=60){
  sec-=60;
  min++;
 }
 if(min>=60){
  min-=60;
  ore++;
 }
}

}

 