#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>
#include <map>
#include "model/Submission.h"
#include "model/Reviewer.h"
#include "model/Config.h"

class CSVReader {
public:
    // Metodo principal que coordena a leitura do ficheiro
    bool parseFile(const std::string& filename,
                   std::map<int, Submission>& submissions,
                   std::map<int, Reviewer>& reviewers,
                   Config& config);

private:
    // Métodos auxiliares para limpar a linha de comentários (#)
    std::string trimAndRemoveComments(const std::string& line);

    // Métodos para processar cada linha dependendo da secção atual
    void parseSubmission(const std::string& line, std::map<int, Submission>& submissions);
    void parseReviewer(const std::string& line, std::map<int, Reviewer>& reviewers);
    void parseParameter(const std::string& line, Config& config);
    void parseControl(const std::string& line, Config& config);
};

#endif