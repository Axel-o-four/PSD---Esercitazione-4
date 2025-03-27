#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

int main(){
  //Inizializzazione delle variabili
  int n=0, s=1, i=0, p1_max, p2_max;
  float x, y, d_max, d_temp;
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
    punti[i]=creaPunto(x, y);
    printf("Realizzato con successo il punto %d\n\n", i);
    n++;
    i++;
    if(n>=2){
      printf("Inserire un altro punto? (0 no, 1 si)");
      scanf("%d", &s);
    }
  }

  for(int j=0; j<(n-1); j++){
    for(int i=j+1; i<n; i++){
      if(j==0&&i==1){
        d_max=distanza(punti[j], punti[i]);
        p1_max=j;
        p2_max=i;
      }else{
        d_temp=distanza(punti[j], punti[i]);
        if(d_temp>d_max){
          d_max=d_temp;
          p1_max=j;
          p2_max=i;
        }
      }
    }
  }
  printf("\n\nLa distanza massima tra le coppie di punti è %.2f tra i punti %d e %d", d_max, p1_max, p2_max);
  return 0;
}
