#ifndef REVIEWER_H
#define REVIEWER_H

#include <string>

struct Reviewer {
    int id;
    std::string name;
    std::string email;
    int primaryExpertise;
    int secondaryExpertise;

    Reviewer(int id, std::string name, std::string email, int primary, int secondary)
        : id(id), name(name), email(email), primaryExpertise(primary), secondaryExpertise(secondary) {}
};

#endif