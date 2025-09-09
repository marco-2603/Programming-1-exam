#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Inserisci il numero di righe del Triangolo di Tartaglia: ";
    cin >> n;

    
    for (int i = 0; i < n; i++) {
        int valore = 1;  // Il primo valore di ogni riga è sempre 1
        
        for (int k = 0; k < n - i - 1; k++) {
            cout << " ";  
        }
        for (int j = 0; j <= i; j++) {
            cout << valore<<" ";  

            valore = valore * (i - j) / (j + 1);
        }
        cout << endl;  
    }

    return 0;
}
