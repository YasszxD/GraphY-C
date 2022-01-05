#include <stdio.h>
#include <stdlib.h>
#include "GraphY.h"
#include <stdbool.h>

int main(int argc, char const *argv[]) {
  struct graph* g1=malloc(sizeof(struct graph));
  g1=new_graph();
  add_node(g1,'A');
  add_node(g1,'B');
  add_node(g1,'C');
  add_node(g1,'D');

  add_edge(g1,'A','B',10);
  add_edge(g1,'A','C',20);
  add_edge(g1,'B','C',5);
  add_edge(g1,'B','D',16);
  add_edge(g1,'C','D',20);

  struct djk* d=dijkestra(g1,'A');
  if(d==NULL){printf("no\n" );goto pass;}

  //print floyd D and P
  int i = 0,j=0;
  for (i = 0; i < graph_order(g1); i++) {
      printf("%d\t",*(d->D+i));
  }
  printf("\n" );printf("\n" );
  //chemin
  for (i = 0; i < graph_order(g1); i++) {
        printf("%d\t",*(d->P+i));
  }

  pass:

  return 0;
}
