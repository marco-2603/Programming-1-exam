 //SORTING BASE DI UNA PILA RICORSIVAMENTE
#include <iostream>
#include <cstdlib>
#include <cassert>

// Non modificare questa parte sotto del codice
typedef struct Stack {
    int data;
    struct Stack * next;
} Stack;

struct Stack * initStack() {
    return nullptr;
}

bool isEmpty(struct Stack * s) {
    return (s == nullptr);
}

void push(struct Stack * &s, int value) {
    struct Stack * newElement = new Stack;
    newElement->data = value;
    newElement->next = s;
    s = newElement;
}

int top(struct Stack * s) {
    if (isEmpty(s)) {
        std::cerr << "top Error: stack is empty" << std::endl;
        assert(false);
        exit(1);
    }
    return s->data;
}

int pop(struct Stack * &s) {
    if (isEmpty(s)) {
        std::cerr << "pop Error: stack is empty" << std::endl;
        assert(false);
        exit(1);
    }
    int value = s->data;
    struct Stack * temp = s;
    s = s->next;
    delete temp;
    return value;
}

int lenght(struct Stack * s) {
    int count = 0;
    struct Stack * temp = s;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteStack(struct Stack * &s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

void printStack(struct Stack * s, const char * message = "Stack: ") {
    if (isEmpty(s)) {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << message;
        struct Stack * temp = s;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}
// Non modificare questa parte sopra del codice

// Inserire qui sotto la dichiarazione della funzione calcola
void ordina(Stack *&s);
// Inserire qui sopra la dichiarazione della funzione calcola


int main() {
    srand(time(NULL));
    struct Stack *s;

    s = initStack();
    for (int i = 0; i < 10; i++) {
        push(s, rand() % 10);
    }
    
    printStack(s, "S: ");
    ordina(s);
    printStack(s, "NS: ");
    deleteStack(s);

    return 0;
}

// Funzione ausiliaria per inserire un elemento in una pila già ordinata
void inserisciInPilaOrdinata(Stack *&s, int elemento) {
    if (isEmpty(s) || top(s) <= elemento) {
        push(s, elemento); // Se la pila è vuota o l'elemento è maggiore o uguale al top
        return;
    }

    int temp = pop(s); // Rimuovi temporaneamente l'elemento in cima
    inserisciInPilaOrdinata(s, elemento); // Ricorsivamente inserisci l'elemento
    push(s, temp); // Ripristina l'elemento originale
}

// Funzione principale per ordinare la pila
void ordina(Stack *&s) {
    if (isEmpty(s)) {
        return; // Caso base: pila vuota
    }

    int temp = pop(s); // Estrai il top della pila
    ordina(s); // Ricorsivamente ordina il resto della pila
    inserisciInPilaOrdinata(s, temp); // Inserisci l'elemento estratto nella posizione corretta
}
