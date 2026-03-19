#ifndef FLOWALGORITHMS_H
#define FLOWALGORITHMS_H

#include "logic/Graph.h"

// Implementação do Edmonds-Karp ou Dinic
// Deve retornar o valor do fluxo máximo atingido
int edmondsKarp(Graph<int> *g, int source, int sink);

#endif