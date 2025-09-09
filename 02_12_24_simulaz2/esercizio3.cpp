//maze classico con pila
#include <iostream>
#include "pila.h"


using namespace std;


/**
 * Ricordare che il file "pila.h" contiene la definizione della struct "cella" (qui sotto riportata)
 * 
 * struct cella {
 *   int indiceRiga;
 *   int indiceColonna;
 * };
 */

// 1 = libero, 0 = percorribile
void risolviLabirinto(int maze[][5], int col, int rig);


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale  

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
    risolviLabirinto(labirinto, 2, 4);

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

bool checkpath(int maze[][5],int col,int rig,int x,int y,int visited[][5]){
 cout<<"ora sono su ["<<x<<"]["<<y<<"]"<<endl;
 //se è arrivato è true
 if(x==col&&y==rig){
  cout<<"ho trovato un percorso"<<endl;
  return true;
 }
 //se ho ripetuto pop() e do falso
 if(maze[x][y]!=1||visited[x][y]){
  cout<<"vicolo CIECO su ["<<x<<"]["<<y<<"]"<<endl;
  pop();
  return false;
 }
 //ho visitato il posto xy
 visited[x][y]=1;

 cella c;

 //check right
 if(y+1<5){
  if(maze[x][y+1]==1){//se destra ho 1
   if(checkpath(maze,col,rig,x,y+1,visited)){//scendo in ricorsione
    c.indiceColonna=x;
    c.indiceRiga=y+1;
    push(c);
    cout<<"vado destra"<<endl;
    return true;
   }
  }
 }

 //check down
 if(x+1<5){
  if(maze[x+1][y]==1){//se giu ho 1
   if(checkpath(maze,col,rig,x+1,y,visited)){//scendo in ricorsione
    c.indiceColonna=x+1;
    c.indiceRiga=y;
    push(c);
    cout<<"vado giu"<<endl;
    return true;
   }
  }
 }

 //check left
 if(y>0){//se non supero i limiti
  if(maze[x][y-1]==1){//se sinistra ho 1
   if(checkpath(maze,col,rig,x,y-1,visited)){//scendo in ricorsione
    c.indiceColonna=x;
    c.indiceRiga=y-1;
    push(c);
    cout<<"vado sinistra"<<endl;
    return true;
   }
  }
 }

 //check up
 if(x>0){
  if(maze[x-1][y]==1){//se su ho 1
   if(checkpath(maze,col,rig,x-1,y,visited)){//scendo in ricorsione
    c.indiceColonna=x-1;
    c.indiceRiga=y;
    push(c);
    cout<<"vado su"<<endl;
    return true;
   }
  }
 }

 //in caso falso
 cout<<"sto pop() su ["<<c.indiceColonna<<"] ["<<c.indiceRiga<<"]"<<endl;
 return false;
}

void risolviLabirinto(int maze [][5], int col, int rig){
 cout<<endl<<"inizia"<<endl;
 init();

 int visited[5][5]={0};

 bool path=checkpath(maze,col,rig,0,0,visited);

 cella c;
 if(path){
  c.indiceColonna=0;
  c.indiceRiga=0;
  push(c);
 }
 cout<<endl;
 //print
 
 while(top(c)){
  cout<<"[" << c.indiceColonna << "," << c.indiceRiga << "]" << endl;
  pop();
 }

}