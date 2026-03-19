#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <string>

struct Submission {
    int id;
    std::string title;
    std::string authors;
    std::string email;
    int primaryDomain;
    int secondaryDomain; // pode ser 0 ou -1 se vazio

    // Construtor útil para o Parser
    Submission(int id, std::string title, std::string authors, std::string email, int primary, int secondary)
        : id(id), title(title), authors(authors), email(email), primaryDomain(primary), secondaryDomain(secondary) {}
};

#endif