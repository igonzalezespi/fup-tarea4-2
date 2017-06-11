#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <limits.h>

#include "common.h"
#include "road.h"
#include "graph.h"

#define MAX_LENGTH 150
#define WRONG_FORMAT "Archivo \"carreteras.txt\" mal formado"

void upload() {
  char aux[MAX_LENGTH];
  char *city_aux;
  char *city_one;
  char *city_two;
  char *weight_aux;
  int weight;
  P_NODO node_aux;
  FILE *file = fopen("./carreteras.txt", "r");

  if (file != NULL) {
    fgets(aux, MAX_LENGTH, file); // Basura
    fgets(aux, MAX_LENGTH, file); // Basura
    fgets(aux, MAX_LENGTH, file); // Lista de ciudades
    aux[strlen(aux)-1] = '\0';
    city_aux = strtok(aux, ", ");
    while (city_aux != NULL) {
      nod = nuevo(nod, city_aux, nodos);
      nodos++;
      city_aux = strtok(NULL, ", ");
    }
    listarNodos(nod);
    fgets(aux, MAX_LENGTH, file); // Basura
    fgets(aux, MAX_LENGTH, file); // Basura
    fgets(aux, MAX_LENGTH, file); // Basura
    while (fgets(aux, MAX_LENGTH, file) != NULL) {
      city_one = strtok(aux, " ");
      city_two = strtok(NULL, " ");
      weight_aux = strtok(NULL, " ");
      weight = atoi(weight_aux);

      puts("1");
      arco(
        buscar(nod, city_one),
        buscar(nod, city_two),
        weight
      );
      puts("10");
    }
    listarNodos(nod);
    node_aux = nod;
    while (node_aux != NULL) {
      puts("\n----ARCOS: -----");
      listarArcos(nod, node_aux->nombre);
      node_aux = node_aux->sgte;
    }
    puts("");
    fclose(file);
  } else {
    puts("No se han encontrado las definiciones");
    puts("Asegurese de que el archivo \"carreteras.txt\" se encuentre en este directorio.");
  }
}

void check_graph() {
  int check[nodos][nodos];
  int i, j;
  P_NODO ii, jj, kk;
  P_ARCO arc;
  char ciudades[nodos][150];
  int fallo;

  // Inicializamos a 0.
  for (i = 0; i<nodos; i++) {
    for (j = 0; j<nodos; j++) {
      check[i][j] = 0;
    }
  }
  // Hacemos la matriz de adyacencia
  ii = nod;
  while (ii != NULL) {
    strcpy(ciudades[ii->index], ii->nombre);

    arc=ii->apunta;
    while (arc != NULL) {
      check[ii->index][arc->apunta->index] = 1;
      // La consideramos sin dirección
      check[arc->apunta->index][ii->index] = 1;
      arc = arc-> sgte;
    }
    ii = ii->sgte;
  }
  // Hacemos Warshall para comprobar que es conexo
  kk = nod;
  while (kk != NULL) {
    ii = nod;
    while (ii != NULL) {
      jj = nod;
      while (jj != NULL) {
        if (check[ii->index][jj->index] != 1) {
          if (
            check[ii->index][kk->index] == 1
            &&
            check[kk->index][jj->index] == 1
          ) {
            check[ii->index][jj->index] = 1;
          }
        }
        jj = jj->sgte;
      }
      ii = ii->sgte;
    }
    kk = kk->sgte;
  }
  // Recorremos ahora en busca de alguien sin relación
  for (i = 0; i<nodos; i++) {
    fallo = 1;
    for (j = 0; j<nodos; j++) {
      if (fallo == 1 && check[i][j]) {
        fallo = 0;
      }
    }
    if (fallo == 1) {
      puts("Archivo no valido.");
      printf("%s es inalcanzable.\n", ciudades[i]);
      break;
    }
  }
  if (fallo == 0) {
    puts("Archivo valido.");
  }
}

void shortest() {
  char aux_origin[MAX_LENGTH],
       aux_destiny[MAX_LENGTH];
  P_NODO origin_node,
         destiny_node;
//         current_node;
//  int i;
//      path[nodos];

  CLEARSCR;
  puts("Indique la ciudad origen:");
  scanf(" %150s", aux_origin);
  origin_node = buscar(nod, aux_origin);
  if (origin_node != NULL) {
    puts("Indique la ciudad destino:");
    scanf(" %150s", aux_destiny);
    destiny_node = buscar(nod, aux_destiny);
    if (destiny_node != NULL) {
      // Aquí me quedo, no me da tiempo...
//      printf(dijkstra(aux_origin, aux_destiny));
    } else {
      puts("Ciudad no existe");
    }
  } else {
    puts("Ciudad no existe");
  }
}
