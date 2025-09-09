using namespace std;
#include <iostream>
#include <cstdlib>


int funzione(char str[]);
void to_minusc(char str[]);

int main(){
 char str[32];
 char continua='n';
 do{
  cout<<"Inserire una stringa di al massimo 31 caratteri"<<endl;
  cin>>str;
  if(funzione(str)==-1){
   cerr<<"ERRORE! nella stringa inserita ci sono caratteri NON alfabetici"<<endl;
  }else {
   cout<<"La somma calcolata è: "<<funzione(str)<<endl;
  }
  cout<<"si vuole ripetere il programma? (s/n)"<<endl;
  cin>>continua;
 }while(continua=='s');

 return 0;
}

int funzione(char str[]){
 int somma=0;
 to_minusc(str);
 if(!(str[0]>='a'&&str[0]<='z')){
  return -1;
 }
 for(int i=1;str[i]!='\0';i++){
  if(!(str[i]>='a'&&str[i]<='z')){
   return -1;
  }
  somma+=abs(str[i]-str[i-1]);
 }

 return somma;
}

void to_minusc(char str[]){
 for(int i=0;str[i] != '\0';i++){
  if(str[i]>='A'&&str[i]<='Z'){
   str[i]=str[i]-'A'+'a';
  }
 }
}