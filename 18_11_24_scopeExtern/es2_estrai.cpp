#include <iostream>
#include <fstream>
#include "es2_estrai.h"
using namespace std;

void estrai_lettera(char *stringa, int index, char *risultato, int indexRis);

char * estrai_stringa(char *stringa){
 char *risultato= new char [MAX_DIM];
 estrai_lettera(stringa, 0, risultato, 0);
 return risultato;
}

void estrai_lettera(char *stringa, int index, char *risultato, int indexRis){
 if(stringa[index]=='\0'){ //controllo se è finita la frase
  risultato[indexRis]='\0';
  return;
  }else if(stringa[index]>='A'&&stringa[index]<='Z'){ //controllo se è maiuscola
  risultato[indexRis]=stringa[index];
  indexRis+=1;
 }
 estrai_lettera(stringa, index+1, risultato, indexRis);
}