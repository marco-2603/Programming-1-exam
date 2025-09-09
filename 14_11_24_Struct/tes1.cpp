// struttura base collisione blocchi
#include <iostream>
#include <cstdlib>
using namespace std;

struct block{
 double m,v;
};

void collisione(block &b1, block &b2){
 int V1=(b1.m*b1.v)/b2.m;
 int V2=(b2.m*b2.v)/b1.m;

 cout<<"la velocità finale della prima collisione è: "<<V1<<endl;
 cout<<"la velocità finale della seconda collisione è: "<<V2<<endl;
}

int main(){
 block b1, b2;
 cout<<"inserire massa primo blocco:"<<endl;
 cin>>b1.m;
 cout<<"inserire velocità primo blocco:"<<endl;
 cin>>b1.v;
 cout<<"inserire massa secondo blocco:"<<endl;
 cin>>b2.m;
 cout<<"inserire velocità secondo blocco:"<<endl;
 cin>>b2.v;

 collisione(b1,b2);

 return 0;
}