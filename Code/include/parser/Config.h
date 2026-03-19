#ifndef CONFIG_H
#define CONFIG_H

#include <string>

struct Config {
    int minReviewsPerSubmission;
    int maxReviewsPerReviewer;
    int generateAssignments; // 0, 1, 2 ou 3
    int riskAnalysis;        // 0, 1 ou K
    std::string outputFileName;
};

#endif