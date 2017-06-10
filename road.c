#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "road.h"
#include "graph.h"

#define MAX_LENGTH 150
#define WRONG_FORMAT "Archivo \"carreteras.txt\" mal formado"

void upload() {
  char aux[MAX_LENGTH];
  char *city;
  char *city_aux;
  char *city_one;
  char *city_two;
  node *node_aux;
  int weight;
  char *weight_aux;
  FILE *file = fopen("./carreteras.txt", "r");
  if (file != NULL) {
    fgets(aux, MAX_LENGTH, file); // Basura
    fgets(aux, MAX_LENGTH, file); // Basura
    fgets(aux, MAX_LENGTH, file); // Lista de ciudades
    aux[strlen(aux)-1] = '\0';
    city_aux = strtok(aux, ", ");
    while (city_aux != NULL) {
      city = (char*)malloc(sizeof(char)*strlen(city_aux)+1);
      strcpy(city, city_aux);
      road = create_node(road, city);
      city_aux = strtok(NULL, ", ");
    }
    list_nodes(road);
    fgets(aux, MAX_LENGTH, file); // Basura
    fgets(aux, MAX_LENGTH, file); // Basura
    fgets(aux, MAX_LENGTH, file); // Basura
    while (fgets(aux, MAX_LENGTH, file) != NULL) {
      city_aux = strtok(aux, " ");
      city_one = (char*)malloc(sizeof(char)*strlen(city_aux)+1);
      strcpy(city_one, city_aux);

      city_aux = strtok(NULL, " ");
      city_two = (char*)malloc(sizeof(char)*strlen(city_aux)+1);
      strcpy(city_two, city_aux);

      city_aux = strtok(NULL, " ");
      weight_aux = (char*)malloc(sizeof(char)*strlen(city_aux)+1);
      strcpy(weight_aux, city_aux);
      weight = atoi(weight_aux);

      create_arc(
        search(road, city_one),
        search(road, city_two),
        weight
      );
    }
    list_nodes(road);
    node_aux = road;
    while (node_aux != NULL) {
      puts("\n----ARCOS: -----");
      list_arcs(road, node_aux->name);
      node_aux = node_aux->next;
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

/////

void clean_string(char c1[]) {
}
