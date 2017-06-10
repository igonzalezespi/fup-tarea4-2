#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"


P_NODO buscar(P_NODO nod, char nombre[150]) {
  P_NODO paux = nod;
  while (paux != NULL) {
    if(strcmp(paux->nombre, nombre) == 0) {
      return paux;
    } else {
      paux = paux->sgte;
    }
  }
  return NULL;
}

void listarArcos(P_NODO nod, char s[150]) {
  P_ARCO arc;
  P_NODO paux = buscar(nod, s);
  if(paux == NULL) {
    printf("\n***El nodo no existe");
  } else {
    printf("\nNodo: %s ", paux->nombre);
    arc=paux->apunta;
    while (arc != NULL) {
      printf("-> arco: %s ", arc->apunta->nombre);
      arc = arc-> sgte;
    }
  }
}

void listarNodos(P_NODO nod) {
  P_NODO paux = nod;

  while (paux!= NULL) {
    printf("\nNodo: %s ", paux->nombre);
    paux = paux->sgte;
  }
}

P_NODO nuevo(P_NODO nod, char nombre[150], int index) {
  if(buscar(nod, nombre) == NULL) {
    P_NODO paux = (P_NODO) malloc(sizeof (NODO));
    strcpy(paux->nombre, nombre);
    paux->index = index;
    paux->apunta = NULL;

    if (nod == NULL) {
      paux->sgte = NULL;
    } else {
      paux->sgte = nod;
    }

    nod = paux;
    printf("\nNodo creado\n");
  } else {
    printf("\nNodo ya creado\n");
  }
  return nod;
}

void arco(P_NODO origen, P_NODO destino, int peso) {
  P_ARCO paux = (P_ARCO) malloc(sizeof (ARCO));

  paux->peso = peso;
  paux->apunta = destino;
  paux->sgte = origen->apunta;
  origen->apunta = paux;
}
