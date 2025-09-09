#include <iostream>
#include "pila.cpp"

using namespace std;


/**
 * Ricordare che il file "pila.h" contiene la definizione della struct "cella" (qui sotto riportata)
 * 
 * struct cella {
 *   int indiceRiga;
 *   int indiceColonna;
 * };
 */
void risolviLabirinto(int [][5], int, int);


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale  

    // E' possibile modificare la matrice per effettuare dei test   
    // E' possibile modificare la matrice per effettuare dei test   
    int labirinto[5][5] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };

    // E' possibile modificare la cella di arrivo per effettuare dei test (la cella di partenza invece è sempre [0,0])   
    cout<<"Percorso: ";
    risolviLabirinto(labirinto, 4, 2);

    int labirinto2[5][5] = {
        { 1, 1, 1, 0, 0 },
        { 0, 1, 0, 0, 0 },
        { 0, 1, 0, 1, 1 },
        { 0, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 0 }
    };

    // E' possibile modificare la cella di arrivo per effettuare dei test (la cella di partenza invece è sempre [0,0])   
    cout<<"Percorso: ";
    risolviLabirinto(labirinto2, 2, 4);

    int labirinto3[5][5] = {
        {1, 0, 0, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1}
    };

    cout << "Percorso: ";
    risolviLabirinto(labirinto3, 4, 2);
   
    return 0;
}

bool checkForPath(int matrix[5][5], int i, int j, int x, int y, int visited[5][5]) {
    if (i == x && j == y) {
        return true;
    }

    if (matrix[i][j] != 1 || visited[i][j]) {
        pop();
        return false;
    }

    // Per evitare di visitare di nuovo le stesse celle
    visited[i][j] = true;

    // i righe
    // j colonne

    // Check down
    // Per prevenire di uscire fuori dall matrice
    cella c;
    if (i+1 < 5) {
        
        if (matrix[i+1][j] == 1) {
            if (checkForPath(matrix, i+1, j, x, y, visited)) {
                c.indiceColonna=i+1;
                c.indiceRiga=j;
                push(c);
                return true;
            }
        }
    }
    // Check right
    if (j+1 < 5) {
        if (matrix[i][j+1] == 1) {
            if (checkForPath(matrix, i, j+1, x, y, visited)) {
                c.indiceColonna=i;
                c.indiceRiga=j+1;
                push(c);
                return true;
            }
        }
    }

    // Check up
    if (i-1 >= 0) {
        if (matrix[i-1][j] == 1) {
            if (checkForPath(matrix, i-1, j, x, y, visited)) {
                c.indiceColonna=i-1;
                c.indiceRiga=j;
                push(c);
                return true;
            }
        }
    }

    // Check left
    if (j-1 >= 0) {
        if (matrix[i][j-1] == 1) {
            if (checkForPath(matrix, i, j-1, x, y, visited)) {
                c.indiceColonna=i;
                c.indiceRiga=j-1;
                push(c);
                return true;
            }
        }
    }


    return false;

}

void risolviLabirinto(int matrix[][5], int x, int y) {

    init();

    // La matrice visited per controllare le coordinate analizzate
    int visited[5][5] = {false};

    bool found = checkForPath(matrix, 0, 0, x, y, visited);
    cella c;
    if (found)
        // Aggiungo le coordinate di partenza
        c.indiceColonna=0;
        c.indiceRiga=0;
        push(c);

    cout << endl;
    while(top(c)) {
        cout << "[" << c.indiceRiga << "," << c.indiceColonna << "]" << endl;
        pop();
    }

}
