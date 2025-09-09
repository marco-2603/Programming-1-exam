using namespace std;
#include <iostream>
#include <cstdlib>


void operazione(float x, float y, char oper);

int main(int argc, char * argv[]){
 float x,y;
 x=atof(argv[1]);
 y=atof(argv[2]);
 char oper;
 oper=*argv[3];

 operazione(x, y, oper);

 return 0;
}

void operazione(float x, float y, char oper){
 if(oper=='+'){
  cout<<x<<" + "<<y<<" = "<<(x+y);
 }
 if(oper=='-'){
  cout<<x<<" - "<<y<<" = "<<(x-y);
 }
 if(oper=='x'){
  cout<<x<<" x "<<y<<" = "<<(x*y);
 }
 if(oper=='/'){
  cout<<x<<" / "<<y<<" = "<<(x/y);
 }
 cout<<endl;
}