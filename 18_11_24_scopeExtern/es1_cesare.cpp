#include <iostream>
#include <fstream>
#include "es1_cesare.h"
using namespace std;

void crypt(char parola [], int chiave){
 for(int i=0;parola[i]!='\0';i++){
  int encrypted= parola[i];
  encrypted+=chiave;
  if(encrypted==' '+chiave){
   encrypted=' ';
  }else if(encrypted>'z'){
   encrypted='z'+'a'+1-encrypted;
  }
  parola[i]=(char)encrypted;
 }
}

void decrypt(char parola [], int chiave){
 for(int i=0;parola[i]!='\0';i++){
  int encrypted= parola[i];
  encrypted-=chiave;
  if(encrypted==' '-chiave){
   encrypted=' ';
  }else if(encrypted<'a'){
   encrypted='z'-'a'+encrypted+1;
  }
  parola[i]=(char)encrypted;
 }
}