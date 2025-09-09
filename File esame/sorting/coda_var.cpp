//SORTING BASE DI UNA CODA
#include <iostream>
#include <cstdlib>
#include <cassert>

// Non modificare questa parte sotto del codice
typedef struct List {
    int data;
    struct List * next;
} List;

typedef struct Queue {
    List * head;
    List * tail;
} Queue;

Queue * initQueue() {
    return new Queue {nullptr, nullptr};
}

bool isEmpty(Queue * s) {
    return ((s != nullptr) && (s->head == s->tail) && (s->head == nullptr));
}

void enqueue(Queue * &s, int value) {
    if (s == nullptr) {
        std::cerr << "enqueue Error: the queue is nullptr" << std::endl;
        assert(false);
        exit(1);
    }
    List * newElement = new List {value, nullptr};
    if (isEmpty(s)) {
        s->tail = s->head = newElement;
    } else {
      s->tail->next = newElement;
      s->tail = newElement;
    }
}

int first(Queue * s) {
    if (isEmpty(s)) {
        std::cerr << "first Error: the queue is empty" << std::endl;
        assert(false);
        exit(1);
    }
    return s->head->data;
}

int dequeue(Queue * &s) {
    if (isEmpty(s)) {
        std::cerr << "dequeue Error: queue is empty" << std::endl;
        assert(false);
        exit(1);
    }
    int value = s->head->data;
    List * temp = s->head;
    if (s->head == s->tail) {
        s->head = s->tail = nullptr;
    } else {
        s->head = s->head->next;
    }
    delete temp;
    return value;
}

int length(Queue * s) {
    int count = 0;
    List * temp = s->head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void reverse(Queue * & s) {
    if (!isEmpty(s)) {
        int v = dequeue(s);
        reverse(s);
        enqueue(s, v);
    }
}

void deleteQueue(Queue * &s) {
    while (!isEmpty(s)) {
        dequeue(s);
    }
}

void printQueue(Queue * s, const char * message = "Queue: ") {
    if (isEmpty(s)) {
        std::cout << message << "Queue is empty" << std::endl;
    }
    else
    {
        std::cout << message;
        List * temp = s->head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}
// Non modificare questa parte sopra del codice

// Inserire qui sotto la dichiarazione della funzione calcola
void ordina(Queue *&q);
// Inserire qui sopra la dichiarazione della funzione calcola


int main() {
    srand(time(NULL));
    struct Queue *q;

    q = initQueue();
    for (int i = 0; i < 10; i++) {
        enqueue(q, rand() % 10);
    }
    
    printQueue(q, "Q: ");
    ordina(q);
    printQueue(q, "NQ: ");
    deleteQueue(q);

    return 0;
}

int findMin(Queue *&q, int n, int minValue) {
    if (n == 0) return minValue;
    int current = dequeue(q);
    enqueue(q, current);
    if(current<minValue){
        return findMin(q, n - 1, current);
    }else{
        return findMin(q, n - 1, minValue);
    }
}

void getMin(Queue *&q, int n, int minValue, int count) {
    if (n == 0) {
        return;
    }
    int current = dequeue(q);
    if (current != minValue || count > 0) {
        enqueue(q, current);
    } else {
        count++;
    }
    getMin(q, n - 1, minValue, count);
}

void ordinaRic(Queue *&q, int n) {
    if (n <= 1) return;

    // Trova il valore minimo nella coda
    int minValue = findMin(q,n,INT_MAX);

    // Rimuovi il minimo dalla coda e reinserisci gli altri
    getMin(q,n,minValue,0);

    // Ordina ricorsivamente il resto della coda
    ordinaRic(q, n - 1);

    // Aggiungi il minimo in fondo alla coda
    enqueue(q, minValue);
}

void ordina(Queue *&q) {
    int n = length(q);
    ordinaRic(q,n);
    //reverse(q); //per renderla crescente
}

