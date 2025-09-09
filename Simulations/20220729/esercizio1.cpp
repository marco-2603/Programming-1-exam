//LEGGI DATI DA FILE, INSERISCI ORDINATAMENTE IN FILE
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

// La funzione non va modificata, pena l'annullamento dell'esercizio
void sort_array(int * array, int len_array) {
  for (int i=0; i<len_array; i++) {
    for (int j=i+1; j<len_array; j++) {
      if (array[i] > array[j]) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
  }
}

int main(int argc, char * argv []) {
	fstream myin,myout;

    if (argc!=4) {
        cerr << "ERRORE, input previsto: ./a.out <filename_in> <DIM> <n>"<<endl;
        return 0;
    }

    myin.open(argv[1],ios::in);
    if (myin.fail()) {
        cerr << "Il file " << argv[1] << " non esiste\n";
        return 0;
    }

    myout.open("output.txt",ios::out);
    if (myout.fail()) {
        cerr << "Il file output.txt non e' scrivibile\n";
        myin.close();
        return 0;
    }
    int dim, n;
    dim=atoi(argv[2]);
    n=atoi(argv[3]);
    if(n>dim){
        cout<<"input da linea di comando errato"<<endl;
        return 1;
    }

    int arr[dim];
    for (int i = 0; i < dim; i++){
        myin>>arr[i];
    }
    sort_array(arr,dim);
    for (int i = dim-1; i > dim-1-n; i--){
        myout<<arr[i]<<endl;
    }

    myin.close();
    myout.close();
    return 0;
}
