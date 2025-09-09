#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Struttura del nodo della lista
struct List {
    int data;
    List *next;
};

// Funzione ausiliaria ricorsiva per ordinare un singolo passaggio di Bubble Sort
bool bubble(List *current) {
    if (current == nullptr || current->next == nullptr) {
        return false; // Nessuna operazione necessaria
    }

    bool swapped = false;
    if (current->data < current->next->data) {
        // Scambia i VALORI dei nodi
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;
        swapped = true;
    }

    // Chiamata ricorsiva sul resto della lista
    return bubble(current->next) || swapped;
}

// Funzione ricorsiva per ordinare la lista in modo decrescente
void ordina(List *&cur, int l) {
    if (cur == nullptr || l <= 1) {
        return; // caso base
    }

    // Esegui un passaggio di Bubble Sort
    if (bubble(cur)) {// Se ci sono stati scambi, ripeti
        ordina(cur, l - 1);
    }
}

// Funzione di supporto per creare un nuovo nodo
List *creaNodo(int valore) {
    List *nuovoNodo = new List;
    nuovoNodo->data = valore;
    nuovoNodo->next = nullptr;
    return nuovoNodo;
}

// Funzione ricorsiva per aggiungere un nodo alla fine della lista
void aggiungiNodo(List *&head, int valore) {
    if (head == nullptr) {
        head = creaNodo(valore);
    } else if (head->next == nullptr) {
        head->next = creaNodo(valore);
    } else {
        aggiungiNodo(head->next, valore);
    }
}

void stampaLista(List *head) {
    if (head == nullptr) {
        cout<<endl;
        return;
    }
    cout << head->data << " ";
    stampaLista(head->next);
}

int main() {
    srand(time(NULL));
    List *lista = nullptr;
    for (int i = 0; i < 10; i++) {
        aggiungiNodo(lista, rand() % 10);
    }

    cout << "Lista originale: "<<endl;
    stampaLista(lista);

    int dim = 10;

    ordina(lista, dim);

    cout << "Lista ordinata in modo decrescente: "<<endl;
    stampaLista(lista);

    return 0;
}
