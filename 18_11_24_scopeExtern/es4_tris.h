#ifndef GIOCO_H
#define GIOCO_H

const int DIM=3;

void inizializzaMatrice (char matrice[DIM][DIM]);
void stampaMatrice(const char matrice[DIM][DIM]);
bool gioca(char matrice[DIM][DIM], bool turnoUtente, char simboloUtente, char simboloComputer);
bool controllaVincita (const char matrice[DIM][DIM], char simbolo, bool &pareggio);
void iniziaGioco(); //da richiamare nel main
#endif