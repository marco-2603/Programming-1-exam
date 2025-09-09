#include <iostream>
using namespace std;

int main (){
 int a,controllo;
  cout<<"inserisci un numero per controllare se è somma tra primi "<<endl;
 cin>>a;
 int primo1,primo2;

 for(int i=1;i<a;i++){
  for(int j=1;j<i;j++)

  controllo=0;
  if(a%i==0){
   primo1=a;
   primo2=primo1-a;
   cout<<primo1<<endl<<primo2<<endl<<endl;
    for(int i=1;i<primo2;i++){
     if(primo2%i==0){
      controllo++;
     }
    }
   if(controllo==1){
   cout<<"una coppia di primi che sommati creano il numero è: "<<endl<<primo1<<" + "<<primo2<<endl;
   }
  }
 }

 return 0;
}
