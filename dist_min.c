#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

#define true 1
#define false 0

int main(){
  int n=0, s=1, i=0;
  float x, y, d, d_temp;
  Punto *punti;
  punti=(Punto *)malloc(1*sizeof(Punto));
  while(s!=0){
    printf("Inserire l'ascissa del punto: ");
    scanf("%f", &x);
    printf("Inserire l'ordinata del punto: ");
    scanf("%f", &y);
    punti[i]=creaPunto(x, y);
    n++;
    i++;
    if(n>=2){
      printf("Inserire un altro punto? (0 no, 1 si)");
      scanf("%d", &s);
    }
  }
  printf("Inserire la distanza minima sotto cui ricercare le coppie di punti: ");
  scanf("%f", &d);
  for(int j=0; j<(n-1); j++){
    for(int i=0; i<n; i++){
      d_temp=distanza(punti[j], punti[i]);
      if(d_temp<d){
        printf("le coppie di punti in posizione %d e %d hanno una distanza %.2f minore della distanza inserita %.2f", j, i, d_temp, d);
      }
    }
  }
}
