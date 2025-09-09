//ANALISI DATI PAZIENTE MEDIA, VARIANZA, struct base statica
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

struct paziente{
 float peso;
 int eta;
 int glicemia [12][31];
};

int monitora(paziente paz, int mese, int ipo, int iper, int &ipogg, float &media, float &varianza);

int main(int argc, char *argv[]){
 if(argc!=5){
  cout<<"Il numero di parametri e’ diverso da 4. Errore! "<<endl;
  return 0;
 }
 int mese=atoi(argv[2]);
 int ipo=atoi(argv[3]);
 int iper=atoi(argv[4]);
 if(ipo<80||ipo>95||iper<105||iper>120||mese<1||mese>12){
  cout<<"I valori di ipoglicemia e iperglicemia non sono corretti. Errore!"<<endl;
  return 0;
 }

 fstream myin;
 myin.open(argv[1], ios::in);

 if(!myin){
  cout<<"Il file non esiste. Errore!"<<endl;
  return 0;
 }

 paziente paz1;
 myin>>paz1.peso;
 myin>>paz1.eta;
 for(int i=0;i<12;i++){
  for(int j=0;j<31;j++){
   myin>>paz1.glicemia[i][j];
  }
 }

 cout<<"il peso è: "<<paz1.peso<<"\n l'eta è: "<<paz1.eta<<endl;
 int ipogg=0;
 float media=0, varianza=0;
 int ipergg=monitora(paz1,mese,ipo,iper,ipogg,media,varianza);

 cout<<"Il numero di giorni di iperglicemia e’: "<<ipergg<<endl;
 cout<<"Il numero di giorni di ipoglicemia e’: "<<ipogg<<endl;
 cout<<"La media e’: "<<media<<endl;
 cout<<"La varianza e’: "<<varianza<<endl;



 myin.close();
 return 0;
}

int monitora(paziente paz, int mese, int ipo, int iper, int &ipogg, float &media, float &varianza){
 int ipergg=0;
 float conta=0;
 for(int i=0;i<31;i++){
  if(paz.glicemia[mese-1][i]>iper){
   ipergg++;
  }
  if(paz.glicemia[mese-1][i]<ipo){
   ipogg++;
  }
  media+=paz.glicemia[mese][i];
 }
 media/=31;

 for(int i=0;i<31;i++){
  conta+=pow(paz.glicemia[mese][i]-media,2);
 }
 varianza=(conta)/30;

 return ipergg;
}