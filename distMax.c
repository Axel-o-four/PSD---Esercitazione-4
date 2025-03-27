#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

int main(){
  //Inizializzazione delle variabili
  int n=0;
  float x, y, d_max;

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

  //Richiamo alla funzione per cercare la distanza massima tra i punti della sequenza
  d_max=cercaDistanzaMassima(s, n);

  printf("\n\nLa distanza massima tra le coppie di punti è %.2f", d_max);
  return 0;
}
