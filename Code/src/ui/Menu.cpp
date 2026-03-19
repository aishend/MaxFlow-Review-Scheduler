/*
 * myProg -b input.csv output.csv
 */

#include "../include/ui/Menu.h"
#include <iostream>
using namespace std;
void Menu::DisplayMainMenu() {


    cout << "       Scientific Conference Organization Tool        \n";
    cout << "1. Load Data Set (.csv)\n";
    cout << "2. List Submissions / Reviewers / Current Parameters\n";
    cout << "3. Generate Review Assignments (Max-Flow)\n";
    cout << "4. Perform Risk Analysis\n";
    cout << "0. Exit\n";
    cout << "------------------------------------------------------\n";
    cout << "Choice: ";
}

// return -1 se nao for validado, 0 se correr bem
int Menu::validateInput() {
    int choice;
    // ler o input
    if (!(cin >> choice)) {
        // valida o input do utilizador
        cin.clear();
        cin.ignore(1000, '\n');
        return -1;
    }
    return 0;
}

void Menu::runMenu() {

    int choice;
    bool keepRunning = true;

    // validar o input
    while (keepRunning) {
        DisplayMainMenu();

        if (validateInput() == -1) {
            cout << "\n[Error]: Invalid input. Please enter a numeric value.\n";
            continue;
        }


        switch (choice) {
            case 1:
                cout << "\nSelected: Load Data Set\n";
                // Chamar T1.2: Read and Parse logic
                break;
            case 2:
                cout << "\nSelected: List Information\n";
                // Mostrar Submissions, Reviewers e Parameters
                break;
            case 3:
                cout << "\nSelected: Generate Assignments\n";
                // T2.1: Max-Flow formulation
                break;
            case 4:
                cout << "\nSelected: Risk Analysis\n";
                // T2.2: Risk Analysis logic
                break;
            case 0:
                cout << "Exiting program...\n";
                keepRunning = false;
                break;
            default:
                cout << "\n[Error]: Invalid option. Please choose between 0 and 4.\n";
                break;
        }
    }
}