//ARRAY DINAMICO
using namespace std;
#include <iostream>
#include <cstdlib>

int * generate_numbers(int n);

int main(int argc, char* argv[]){
 srand(time(NULL));

 if(argc!=2){
 cout<<"Usage: <./a.out> <n> "<<endl;
 return 0;
 }
 int n;
 n=atoi(argv[1]);

 int *arr=generate_numbers(n);

 for(int i=0;i<n;i++){
  cout<<arr[i]<<" ";
 }
 cout<<endl;

 delete[] arr;
 return 0;
}

int * generate_numbers(int n){
 int * array = new int [n];

 for(int i=0;i<n;i++){
  array[i]=rand()%100;
 }
 cout<<endl;

 return array;
}