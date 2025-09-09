#include "priorityQ.h"
#include <iostream>

using namespace std;

/*struct node {
  int value;
  node *left = nullptr;
  node *right = nullptr;
};

struct priorityQueue {
  node **queue;
  int dim;
};*/

priorityQueue *init(int dim){
 priorityQueue *coda=new priorityQueue[dim];
 coda->queue=new node*[dim];
 coda->dim=dim;
 return coda;
}

void enqueue(priorityQueue &pq, int value, int priority){ //qui pq è passato per rif quindi per accedere agli elem uso pq.qualcosa perchè pq non è il puntatore ma la struct in se
 node *corrente=pq.queue[priority];
 if(priority>pq.dim-1){
  cerr<<"ERRORE, priority inserita troppo alta"<<endl;
  return;
 }
 if(corrente==nullptr){
  node *corrente=new node;
  corrente->value=value;
  pq.queue[priority]=corrente;
 }else{
  while(corrente->right!=nullptr){
   corrente->left=corrente;
   corrente=corrente->right;
  }
  node *nuovo=new node;
  nuovo->value=value;
  nuovo->left=corrente;
  nuovo->right=nullptr;
  corrente->right=nuovo;
 }
}

int dequeue(priorityQueue &pq){
 int i=0;
 while(pq.queue[i]==nullptr&&i<pq.dim){
  i++;
 }
 if(i==pq.dim){
  return -1;
 }
 int k=pq.queue[i]->value;
 if(pq.queue[i]->right!=nullptr){
  pq.queue[i]=pq.queue[i]->right;
  delete pq.queue[i]->left;
  pq.queue[i]->left=nullptr;
 }else {
  delete pq.queue[i];
  pq.queue[i]=nullptr;
 }
 return k;
}

void print(priorityQueue &pq){
 for(int i=pq.dim-1;i>=0;i--){
  cout<<"La coda a priorità ["<<i<<"] è:"<<endl;
  node *corrente=pq.queue[i];
  if(corrente!=nullptr){
   cout<<corrente->value<<"\t";
   while(corrente->right!=nullptr){
   corrente=corrente->right;
   cout<<corrente->value<<"\t";
  }
  }
  
  cout<<endl;
 }
}

void dealloc(priorityQueue &pq){
 while(dequeue(pq)!=-1){

 }
 delete[] pq.queue;
 delete &pq;
}