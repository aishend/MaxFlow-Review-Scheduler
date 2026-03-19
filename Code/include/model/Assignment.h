#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <vector>
#include <string>

// Estrutura para representar uma única atribuição
struct Assignment {
    int submissionId;
    int reviewerId;
    int matchedDomain; // O domínio (ID) que causou a compatibilidade
};

// Estrutura para o relatório de submissões com revisões em falta (Tarefa 2.1 - Erro)
struct MissingReview {
    int submissionId;
    int domain;
    int missingCount;
};

#endif