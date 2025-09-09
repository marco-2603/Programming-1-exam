#include <iostream>
using namespace std;

void swapbit(short *n1,short *n2);

int main (){
 short n1,n2;
 n1=1855;
 n2=1048;
 cout<<"numeri prima: "<<endl<<n1<<endl<<n2<<endl;
 swapbit(&n1, &n2);
 cout<<"numeri dopo: "<<endl<<n1<<endl<<n2<<endl;

 return 0;
}

void swapbit(short *n1, short *n2){
 char *pn1=(char*)n1; //il casting serve per far considerare la cella di memora di n1 come un char che quindi mi va a considerare solo un byte (lunghezza char)
 char *pn2=(char*)n2;
 char temp=*(pn1+1); //essendo char prendo una cella, la cella appena dopo quindi la seconda cella di n1
 *(pn1+1)=*(pn2+1);
 *(pn2+1)=temp;
}

/*
In alternativa:
metodo1: divido i byte del numero per quanto mi serve per escludere un solo byte, li scambio e gli rimetto il byte che ho estratto
Metodo2: li ha convertiti in binario e ha fatto un and bit-a-bit con la maschera
*/
