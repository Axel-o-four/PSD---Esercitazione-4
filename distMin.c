#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

int main(){
  //Inizializzazione delle variabili
  int n=0, s=1, i=0, n_coppie=0;
  float x, y, d, d_temp;
  Punto *punti;
  punti=(Punto *)malloc(sizeof(Punto));

  //Controllo dell'allocazione dell'array
  if(punti==NULL){
    fprintf(stderr, "Errore nell'allocazione dell'array di punti!");
    exit(EXIT_FAILURE);
  }

  //Ciclo di inserimento dei punti
  while(s!=0){
    printf("Inserire l'ascissa del punto: ");
    scanf("%f", &x);
    printf("Inserire l'ordinata del punto: ");
    scanf("%f", &y);
    printf("\n");
    punti[i]=creaPunto(x, y);
    n++;
    i++;
    if(n>=2){
      printf("Inserire un altro punto? (0 no, 1 si)");
      scanf("%d", &s);
    }
  }

  printf("\nInserire la distanza minima sotto cui ricercare le coppie di punti: ");
  scanf("%f", &d);
  for(int j=0; j<(n-1); j++){
    for(int i=j+1; i<n; i++){
      d_temp=distanza(punti[j], punti[i]);
      if(d_temp<d){
        printf("\nle coppie di punti in posizione %d e %d hanno una distanza %.2f minore della distanza inserita %.2f", j, i, d_temp, d);
        n_coppie++;
      }
    }
  }
  printf("\n\nIl numero di coppie di punto con una distanza minore di %.2f è %d", d, n_coppie);
  return 0;
}
