#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

typedef struct arc {
  int weight;
  struct arc *next;
  struct node *point;
} arc;

typedef struct node {
  char *name;
  struct node *next;
  struct arc *point;
} node;

extern node* road;

node* search(node *n, char *name);
void list_arcs(node *n, char *name);
void list_nodes(node *n);
node* create_node(node *n, char *name);
void create_arc(node *origin, node *destiny, int weight);

#endif // GRAPH_H_INCLUDED
