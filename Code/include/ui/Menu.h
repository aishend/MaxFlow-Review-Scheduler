#ifndef MENU_H
#define MENU_H

#include "logic/ConferenceManager.h"

class Menu {
public:
    void DisplayMainMenu();
    int validateInput();
    void runMenu();
};

#endif