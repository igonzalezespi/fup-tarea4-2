//// Libraries
#include <stdio.h>
#include <ctype.h>
#include <windows.h>

#include "common.h"

//// Main

int main() {
  SetConsoleTitle(TITLE);
  execute();
  system("PAUSE");
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
  }
  system("PAUSE");
  execute();
}








