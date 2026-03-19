/*

#ifndef CONFERENCEMANAGER_H
#define CONFERENCEMANAGER_H

#include <map>
#include <vector>
#include "model/Submission.h"
#include "model/Reviewer.h"
#include "model/Config.h"
#include "model/Assignment.h"
#include "logic/Graph.h" // A classe de grafos da FEUP

class ConferenceManager {
public:
    // Recebe os dados lidos pelo Parser
    ConferenceManager(std::map<int, Submission> subs, std::map<int, Reviewer> revs, Config cfg);

    // Constrói o grafo de fluxo baseado nos parâmetros
    void buildFlowGraph();

    // Executa o algoritmo de Max-Flow (Edmonds-Karp)
    bool solveAssignment();

    // Executa a Análise de Risco (Tarefa 2.2)
    std::vector<int> performRiskAnalysis();

    // Gera os resultados para o ficheiro de saída
    void exportResults(std::string filename);

private:
    std::map<int, Submission> submissions;
    std::map<int, Reviewer> reviewers;
    Config config;
    Graph<int> flowGraph; // Grafo onde os nós são IDs (ou índices)

    // Métodos auxiliares para adicionar arestas de compatibilidade
    bool areCompatible(const Submission& s, const Reviewer& r);
};

#endif

*/