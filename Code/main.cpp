#include <iostream>
#include <string>
#include "./include/ui/Menu.h"
// esta deve ser a estrutura
using namespace std;

int main(int argc, char* argv[]) {

    if (argc == 1) {
        Menu menu;
        menu.runMenu();
    }

    else if (argc == 4 && string(argv[1]) == "-b") {
        string inputFile = argv[2];
        string outputFile = argv[3];
        printf("debug - args received");
        // batch mode e passa os parametros do ficheiro de entrada e o ficheiro de saida
        return 0;
    }

    else {
        // mensagem de erro
        cerr << "Error: Invalid arguments." << endl;
        cerr << "Usage: " << argv[0] << " [-b <input.csv> <output.csv>]" << endl;
        return 1; // Return an error code
    }

}

