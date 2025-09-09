using namespace std;
#include <iostream>
#include <cstdlib>
#include <fstream>

int main(int argc, char * argv[]){
 fstream myfile,myout;
 char file[41],fileout[41],lettera;
 cout<<"inserire il nome di un file da leggere e uno su cui scrivere"<<endl;
 cin>>file>>fileout;

 myfile.open(file,ios::in);
 myout.open(fileout,ios::out);
 if (myfile.fail()) {
 cerr << "Il file " << file << " non esiste\n";
 return 0;
 }

 cout<<"inserire una letera da sostituire"<<endl;
 cin>>lettera;

 cout<<"il contenuto del file insertito è: "<<endl;
 char arr[100];
 while(!myfile.eof()){
 myfile.getline(arr, 100, '\n');
 cout<<arr<<endl;
 }

 myfile.seekg(0, ios::beg);

  char c;
 while (myfile.get(c)) {
  if(c==lettera){
   myout.put('?');
   cout<<'?';
  }
  else {
   myout.put(c);
   cout<<c;
  }
 }

  myfile.close();
  myout.close();
 return 0;
}

