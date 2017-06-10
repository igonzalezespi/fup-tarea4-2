#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "road.h"
#include "graph.h"

#define MAX_LENGTH 150
#define WRONG_FORMAT "Archivo \"carreteras.txt\" mal formado"

void upload() {
  char aux[MAX_LENGTH];
  char *city_aux;
  char *city_one;
  char *city_two;
//  char *weight_aux;
//  int weight;
  P_NODO node_aux;
  FILE *file = fopen("./carreteras.txt", "r");

  if (file != NULL) {
    fgets(aux, MAX_LENGTH, file); // Basura
    fgets(aux, MAX_LENGTH, file); // Basura
    fgets(aux, MAX_LENGTH, file); // Lista de ciudades
    aux[strlen(aux)-1] = '\0';
    city_aux = strtok(aux, ", ");
    while (city_aux != NULL) {
      nod = nuevo(nod, city_aux);
      city_aux = strtok(NULL, ", ");
    }
    listarNodos(nod);
    fgets(aux, MAX_LENGTH, file); // Basura
    fgets(aux, MAX_LENGTH, file); // Basura
    fgets(aux, MAX_LENGTH, file); // Basura
    while (fgets(aux, MAX_LENGTH, file) != NULL) {
      city_one = strtok(aux, " ");
      city_two = strtok(NULL, " ");
//      weight_aux = strtok(NULL, " ");
//      weight = atoi(weight_aux);

      puts("1");
      arco(
        buscar(nod, city_one),
        buscar(nod, city_two)
//        weight
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
    fclose(file);
  } else {
    puts("No se han encontrado las definiciones");
    puts("Asegurese de que el archivo \"carreteras.txt\" se encuentre en este directorio.");
  }
}

void check_graph() {
  puts("check_graph!");
}

void shortest() {
  puts("shortest!");
}
