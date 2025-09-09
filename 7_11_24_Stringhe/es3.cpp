using namespace std;
#include <iostream>
#include <cstdlib>
#include <fstream>

int main(int argc, char * argv[]){
 fstream myin,myout;

 if (argc!=3) {
  cerr << "ERRORE, input previsto: ./a.out <filename_in> <filename_out>"<<endl;
  return 0;
 }

 myin.open(argv[1],ios::in);
 if (myin.fail()) {
  cerr << "Il file " << argv[1] << " non esiste\n";
  return 0;
 }

 myout.open(argv[2],ios::out);
 if (myout.fail()) {
  cerr << "Il file " << argv[2] << " non e' scrivibile\n";
  myin.close();
  return 0;
 }

 char arr[100];
 while(!myin.eof()){
 myin.getline(arr, 100, '\n');
 cout<<arr<<endl;
 }
 cout<<endl;
 myin.seekg(0, ios::beg);
 
 char c;
 while (myin.get(c)) {
  myout.put(c);
 }

 myin.close();
 myout.close();
 return 0;
}

