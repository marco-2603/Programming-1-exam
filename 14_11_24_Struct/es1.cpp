// Esse3++ (studenti)
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

struct Studente{
 char nome[31];
 char cognome[31];
 int matricola;
 float media;
};

void stampa_studente(Studente *s){
 cout<<"i dati dello studente sono:"<<endl;
 cout<<"nome: "<<s->nome<<endl;
 cout<<"cognome: "<<s->cognome<<endl;
 cout<<"matricola: "<<s->matricola<<endl;
 cout<<"media: "<<s->media<<endl<<endl;
}

Studente *genera_studente(char nome[], char cognome[], int matricola, float media){
 Studente *s=new Studente;
 s->matricola=matricola;
 s->media=media;
 strcpy(s->nome,nome);
 strcpy(s->cognome,cognome);
 return s;

}

int main(){
 char nome[31], cognome[31];
 int matricola;
 float media;
 fstream myin;

 cout<<"inserire i dati dello studente: <nome> <cognome> <matricola> <media>"<<endl;
 cin>>nome>>cognome>>matricola>>media; //prendo i dati dello studente

 Studente *s1=genera_studente(nome,cognome,matricola,media); //genero studente
 stampa_studente(s1); //stampo lo studente

 delete s1; //dealloco la memoria

 return 0;
}