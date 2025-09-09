#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

void elaborariga(char str[127], int num[13], int &ris);
int converti(int b[8], int n);
int somma(int a[], int n);


int main(){
 fstream myin, myout;
 myin.open("inputdati.txt", ios::in);
 if (myin.fail()) {
  cerr << "Il file " << "inputdati.txt" << " non esiste\n";
  return 0;
 }

 myout.open("outputcheck.txt", ios::out);
 if (myout.fail()) {
  cerr << "Il file " << "outputcheck.txt" << " non e' scrivibile\n";
  myin.close();
  return 0;
 }
 myout.close();

 char riga[127];
 while(myin.getline(riga, 127)){
  cout<<"prendo riga: "<<riga<<endl;
  int num[13];
  int ris;
  for(int i=0;i<13;i++){
   num[i]=0;
  }

  elaborariga(riga,num,ris);
  
 }


 myin.close();

 return 0;
}

void elaborariga(char str[127], int num[13], int &ris){
 cout<<"ENTRO NELLA FUNZIONE"<<endl;
 char s=0; //legge il carattere
 int i=0; //scorre la riga
 int j=0; //lunghezza di num
 int len=0;
 int b[8];
 while(s!='='){ 
  for(int k=0;k<8;k++){ //converte i numeri e inserisce su num
   b[k]=0;
  }
  len=0;
  s=str[i];
  cout<<"il numero:";
  while(s!='+'&&s!='='){ //prende i singoli 0/1 e li inserisce in b
   cout<<"["<<s<<"] ";
   if(s=='1'){
    b[len]=1;
   }else if(s=='0'){
    b[len]=0;
   }
   i++;
   len++;
   s=str[i];
  }
  num[j]=converti(b,len);
  cout<<endl<<"diventa il decimale : "<<num[j]<<endl;
  j++;
  i++;
 }
 for(int k=0;k<8;k++){
   b[k]=0;
  }
 len=0;
 s=str[i];
 while(s!=';'){ // ora mette il risultato della stringa su ris
   cout<<"["<<s<<"] ";
   if(s=='1'){
    b[len]=1;
   }else if(s=='0'){
    b[len]=0;
   }
   i++;
   len++;
   s=str[i];
  }
 ris=converti(b,len);
 cout<<endl<<"diventa il decimale : "<<ris<<endl;

 int sum=somma(num,j);
 cout<<"la somma della riga è= "<<sum<<endl;

 fstream myout;
 myout.open("outputcheck.txt", ios::app);
 if(sum==ris){
  for(int i=0;i<j-1;i++){
   myout<<num[i]<<"+";
  }
  myout<<num[j-1]<<"="<<ris<<endl;
 }else{
  myout<<"ERRORE"<<endl;
 }
 myout.close();
}

int converti(int b[8], int n){
 int ris=0, j=n-1;
 cout<<endl<<"l'array b è:";
 for(int i=0;i<n;i++){
  cout<<"["<<b[i]<<"] ";
 }
 for(int i=0;i<n;i++){
  if(b[j]){
   ris+=pow(2,i);
  }
  j--;
 }
 return ris;
}

int somma(int a[], int n){
 int sum=0;
 for(int i=0;i<n;i++){
  sum+=a[i];
 }
 return sum;
}