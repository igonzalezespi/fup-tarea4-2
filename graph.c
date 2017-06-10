#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

node* search(node *n, char *name) {
  node *aux = n;
  while (aux != NULL) {
    if(strcmp(aux->name, name) == 0) {
      return aux;
    } else {
      aux = aux->next;
    }
  }
  return NULL;
}

void list_arcs(node *nod, char *name) {
  arc* arc;
  node* aux = search(nod, name);
  if(aux == NULL) {
    puts("***El nodo no existe");
  } else {
    printf("Nodo: %s", aux->name);
    arc=aux->point;
    while (arc != NULL) {
      printf("-> arc: %s (%i) ", arc->point->name, arc->weight);
      arc = arc-> next;
    }
  }
}

void list_nodes(node* nod) {
  node* aux = nod;
  while (aux!= NULL) {
    printf("Nodo: %s\n", aux->name);
    aux = aux->next;
  }
}

node* create_node(node* nod, char *name) {
  if(search(nod, name) == NULL) {
    node* aux = (node*)malloc(sizeof(node));
    aux->name = name;
    aux->point = NULL;

    if (nod == NULL) {
      aux->next = NULL;
    } else {
      aux->next = nod;
    }

    nod = aux;
  } else {
    puts("Nodo ya creado");
  }
  return nod;
}

void create_arc(node* origin, node* destiny, int weight) {
  arc* aux = (arc*) malloc(sizeof (arc));

  aux->weight = weight;
  aux->point = destiny;
  aux->next = origin->point;
  origin->point = aux;
}

void warshal(int p[10][10],int n) {
  int i,j,k;
  for (k=1; k<=n; k++)
    for (i=1; i<=n; i++)
      for (j=1; j<=n; j++)
        p[i][j]=max(p[i][j],p[i][k]&&p[k][j]);
}

int max(int a,int b) {
  if(a > b)
    return(a);
  return(b);
}
