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
