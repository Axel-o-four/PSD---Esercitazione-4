#include <stdio.h>
#include <math.h>
#include "punto.h"

//Definizione della struct punto
typedef struct{
  float ascissa;
  float ordinata;
}punto;

//Funzione di inizializzazione di un punto
Punto creaPunto(float x, float y){
  Punto p;
  p=(Punto)calloc(1,sizeof(punto));
  p->ascissa=x;
  p->ordinata=y;
  return p;
}

float ascissa(Punto p){
  return p->ascissa;
}

float ordinata(Punto p){
  return p->ordinata;
}

float distanza(Punto p1, Punto p2){
  float d;
  d=sqrt(pow((p1->ascissa-p2->ascissa),2)+pow((p1->ordinata-p2->ordinata),2));
  return d;
}
