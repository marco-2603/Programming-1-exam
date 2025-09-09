//sorting di una lista scambiando o i nodi o solo i valori
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Struttura del nodo della lista
struct List {
    int data;
    List *next;
};

void swapVal(List *a, List *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void swapNodes(List *&head, List *prevA, List *a, List *prevB, List *b) {
    if (a == b) return;

    // Aggiorna i puntatori dei nodi precedenti
    if (prevA != nullptr) {
        prevA->next = b;
    } else {
        head = b;
    }

    if (prevB != nullptr) {
        prevB->next = a;
    } else {
        head = a;
    }

    // Scambia i puntatori next
    List *temp = a->next;
    a->next = b->next;
    b->next = temp;
}

// Funzione ricorsiva per ordinare la lista in modo decrescente
void ordina(List *&cur, int l) {
    if (cur == nullptr || l <= 1) {
        return; // Nessuna operazione necessaria
    }

    for (int i = 0; i < l - 1; i++) {
        List *prev = nullptr; //solo per quando scambio i nodi
        List *current = cur;
        List *next = cur->next;

        while (next != nullptr) {
            if (current->data < next->data) {
                // Scambia i valori dei nodi
                swapVal(current,next);
                //scambi I NODI
                //swapNodes(cur, prev, current, current, next);
            }
            prev = current; //solo per quando scambio i  nodi
            current = next;
            next = next->next;
        }
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
