#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"

//Definizione della struct punto
struct punto{
  float ascissa;
  float ordinata;
};

//Funzione di inizializzazione di un punto
Punto creaPunto(float x, float y){
  Punto p;
  p=(Punto)calloc(1,sizeof(struct punto));
  if(p==NULL){
    fprintf(stderr, "Impossibile allocare la memoria per il punto!");
    exit(EXIT_FAILURE);
  }
  p->ascissa=x;
  p->ordinata=y;
  return p;
}

//Funzione di ritorno dell'ascissa di un punto
float ascissa(Punto p){
  return p->ascissa;
}

//Funzione di ritorno dell'ordinata di un punto
float ordinata(Punto p){
  return p->ordinata;
}

//Funzione di calcolo della distanza fra due punti
float distanza(Punto p1, Punto p2){
  float d;
  d=sqrt(pow((p1->ascissa-p2->ascissa),2)+pow((p1->ordinata-p2->ordinata),2));
  return d;
}

//Funzione di spostamento di un punto dato un certo delta x e delta y
void spostaPunto(Punto p, float dx, float dy){
  p->ascissa+=dx;
  p->ordinata+=dy;
}

//Funzione di calcolo del punto centroide data una sequenza di punti
Punto centroide(Punto *punti, int n){
  int i;
  float x_media=0.0, y_media=0.0;
  for(i=0; i<n; i++){
    x_media+=punti[i]->ascissa;
    y_media+=punti[i]->ordinata;
  }
  Punto centroide;
  centroide=(Punto)malloc(sizeof(struct punto));
  centroide->ascissa=(x_media/n);
  centroide->ordinata=(y_media/n);
  return centroide;
}

//Funzione per riempire una sequenza di punti data in input
void riempiPunti(Punto *s, int n){
  float x, y;
  for(int i=0; i<n; i++){
    printf("\nInserire l'ascissa del punto %d: ", i);
    scanf("%f", &x);
    printf("Inserire l'ordinata del punto %d: ", i);
    scanf("%f", &y);
    s[i]=creaPunto(x, y);
  }
}

//Funzione per ricercare le coppie di punti con distanza minore di un certo d
int cercaDistanzaMinore(Punto *s, int n, float d){
  float d_punti;
  int n_coppie;
  for(int j=0; j<(n-1); j++){
    for(int i=j+1; i<n; i++){
      d_punti=distanza(s[j], s[i]);
      if(d_punti<d){
        n_coppie++;
      }
    }
  }
  return n_coppie;
}

//Funzione per ricercare la distanza massima tra le coppie di una sequenza di punti
int cercaDistanzaMassima(Punto *s, int n){
  float d_max, d_temp;
  for(int j=0; j<(n-1); j++){
    for(int i=j+1; i<n; i++){
      if(j==0&&i==1){
        d_max=distanza(s[j], s[i]);
      }else{
        d_temp=distanza(s[j], s[i]);
        if(d_temp>d_max){
          d_max=d_temp;
        }
      }
    }
  }
  return d_max;
}
