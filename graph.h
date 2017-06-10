#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

typedef struct arco {
  struct arco *sgte;
  struct nodo *apunta;
} ARCO, *P_ARCO;

typedef struct nodo {
  char nombre[150];
  struct nodo *sgte;
  struct arco *apunta;
} NODO, *P_NODO;

extern P_NODO nod;

P_NODO buscar(P_NODO nod, char nombre[150]);
void listarArcos(P_NODO nod, char s[150]);
void listarNodos(P_NODO nod);
P_NODO nuevo(P_NODO nod, char nombre[150]);
void arco(P_NODO origen, P_NODO destino);

#endif // GRAPH_H_INCLUDED
