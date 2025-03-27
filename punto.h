//Header file del modulo punto.c

//Definizione del tipo puntatore a punto
typedef struct punto *Punto;

//Prototipi delle funzioni di punto.c
punto creaPunto(float x, float y);
float ascissa(punto p);
float ordinata(punto p);
float distanza(punto p1, punto p2);
