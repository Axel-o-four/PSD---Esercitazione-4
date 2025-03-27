//Header file del modulo punto.c

//Definizione del tipo puntatore a punto
typedef struct punto *Punto;

//Prototipi delle funzioni di punto.c
Punto creaPunto(float x, float y);
float ascissa(Punto p);
float ordinata(Punto p);
float distanza(Punto p1, Punto p2);
void spostaPunto(Punto p, float dx, float dy);
Punto centroide(Punto *punti, int n);
