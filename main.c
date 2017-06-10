//// Libraries
#include <stdio.h>
#include <ctype.h>
#include <windows.h>

#include "common.h"
#include "graph.h"
#include "road.h"

int nodos = 0;
P_NODO nod = NULL;

//// Main

int main() {
  SetConsoleTitle(TITLE);
  execute();
  return (EXIT_SUCCESS);
}

//// Primary functions

void show_menu() {
  CLEARSCR;
  puts("======================");
  puts("Seleccione una opcion");
  puts("======================");
  puts("");
  puts("# Acciones");
  if (nodos == 0) {
    puts("  1 - Cargar");
  } else {
    puts("  1 - Comprobar");
  }
  puts("  2 - Ruta mas corta");
  puts("  S - Salir");
}

char get_option() {
  char aux;
  scanf(" %c", &aux); // Ignoring trailing whitespace
  if (islower(aux)) {
    aux = toupper(aux); // Comparing to uppercase
  }
  return aux;
}

void execute() {
  char option;
  show_menu();
  option = get_option();
  CLEARSCR;
  if (option == 'S') {
    exit(EXIT_SUCCESS);
  } else if (option == '1') {
    if (nodos == 0) {
      upload();
    } else {
      check_graph();
    }
    system("PAUSE");
  }
  execute();
}








