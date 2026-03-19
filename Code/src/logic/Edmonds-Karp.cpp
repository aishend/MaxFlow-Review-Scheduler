// Original code by Gonçalo Leão
// Updated by DA 2024/2025 Team

#include "../data_structures/Graph.h"

// Function to test the given vertex 'w' and visit it if conditions are met
template <class T>
void testAndVisit(std::queue< Vertex<T>*> &q, Edge<T> *e, Vertex<T> *w, double residual) {
    // Check if the vertex 'w' is not visited and there is residual capacity
    if (! w->isVisited() && residual > 0) {
        // Mark 'w' as visited, set the path through which it was reached, and enqueue it
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

// Function to find an augmenting path using Breadth-First Search
template <class T>
bool findAugmentingPath(Graph<T> *g, Vertex<T> *s, Vertex<T> *t) {
    // Mark all vertices as not visited
    for(auto v : g->getVertexSet()) {
        v->setVisited(false);
        v->setPath(nullptr);

    }

    std::queue<Vertex<T>*> q;
    q.push(s);
    s->setVisited(true);
    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();

        // 1. Arestas Diretas (Outgoing)
        for (auto e : tmp->getAdj()) {
            double residual = e->getWeight() - e->getFlow();
            testAndVisit(q, e, e->getDest(), residual);
        }

        // 2. Arestas Reversas (Incoming)
        // No Edmonds-Karp completo, precisamos de olhar para quem entra em 'tmp'
        // para podermos "retirar" fluxo se necessário.
        for (auto e : tmp->getIncoming()) {
            double residual = e->getFlow(); // O residual aqui é o que podemos "tirar"
            testAndVisit(q, e, e->getOrig(), residual);
        }
    }

    // Return true if a path to the target is found, false otherwise
    return t->isVisited();
}

// Function to find the minimum residual capacity along the augmenting path
template <class T>
double findMinResidualAlongPath(Vertex<T> *s, Vertex<T> *t) {
    double f = INF;
    auto curr = t;
    while (curr != s) {
        auto e = curr->getPath();
        double residual;

        if (e->getDest() == curr) { // Aresta Direta
            residual = e->getWeight() - e->getFlow();
            curr = e->getOrig();
        } else { // Aresta Reversa
            residual = e->getFlow();
            curr = e->getDest();
        }

        if (residual < f) f = residual;
    }
    return f;
}

// Function to augment flow along the augmenting path with the given flow value
template <class T>
void augmentFlowAlongPath(Vertex<T> *s, Vertex<T> *t, double f) {
    // Traverse the augmenting path and update the flow values accordingly
 
    auto curr = t;
    while (curr != s) {
        auto e = curr->getPath();
        // Se o curr for o destino da aresta, é uma aresta direta
        if (e->getDest() == curr) {
            e->setFlow(e->getFlow() + f);
            curr = e->getOrig();
        }
        // Se o curr for a origem, estamos a percorrer uma aresta que entrava nele (reversa)
        else {
            e->setFlow(e->getFlow() - f);
            curr = e->getDest();
        }
    }
}

// Main function implementing the Edmonds-Karp algorithm
template <class T>
void edmondsKarp(Graph<T> *g, int source, int target) {
    // Find source and target vertices in the graph
    Vertex<T>* s = g->findVertex(source);
    Vertex<T>* t = g->findVertex(target);
    if (s == nullptr || t == nullptr) return;

    for (auto v : g->getVertexSet()) {
        for ( auto e : v->getAdj()) {
            e->setFlow(0);
        }
    }

    while (findAugmentingPath(g, s, t)) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);

    }
}

