#ifndef CONFERENCEMANAGER_H
#define CONFERENCEMANAGER_H

#include <vector>
#include <string>
#include <unordered_map>
#include "../model/Reviewer.h"
#include "../model/Submission.h"
#include "../data_structures/Graph.h"

enum NodeType {SOURCE, SINK, REVIEWER, SUBMISSION};

struct FlowNode {
    NodeType type;
    int id;

    
};
class ConferenceManager {
private:
    Graph<std::string> graph; // Grafo de strings para podermos usar IDs como "R_1", "S_31", "source", "sink"

    std::unordered_map<int, Reviewer> reviewers;
    std::unordered_map<int, Submission> submissions;

    int minReviewsPerSubmission = 0;
    int maxReviewsPerReviewer = 0;

public:
    ConferenceManager() = default;

    // Métodos para o teu colega injetar dados
    void addReviewer(const Reviewer& r);
    void addSubmission(const Submission& s);
    void setParameters(int minRev, int maxRev);

    void buildBasicGraph(); 

    void assignReviews(); 
};

#endif