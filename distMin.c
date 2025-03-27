#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

int main(){
  //Inizializzazione delle variabili
  int n=0, i=0, m;
  float x, y, d=0.0, d_temp;

  //Inserimento numeri di punti
  while(n<2){
    printf("Quanti punti si vogliono inserire: ");
    scanf("%d", &n);
    if(n>=2){
      break;
    }else{
      printf("Inserire un numero maggiore di 2!\n");
    }
  }

  Punto *s;
  s=(Punto *)malloc(n*sizeof(Punto));

  //Controllo dell'allocazione dell'array
  if(s==NULL){
    fprintf(stderr, "Errore nell'allocazione dell'array di punti!");
    exit(EXIT_FAILURE);
  }

  //Richiamo alla funzione per riempire i punti della sequenza allocata
  riempiPunti(s, n);

  while(d<=0){
    printf("\nInserire la distanza minima sotto cui ricercare le coppie di punti: ");
    scanf("%f", &d);
    if(d>0){
      break;
    }else{
      printf("Inserire una distanza maggiore di 0!\n");
    }
  }

  //Richiamo alla funzione per trovare il numero di coppie con distanza minore di d
  m=cercaDistanzaMinore(s, n, d);

  printf("\nIl numero di coppie di punto con una distanza minore di %.2f è %d", d, m);
  return 0;
}
