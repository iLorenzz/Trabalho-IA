#include <iostream>
#include "parser/parser.hpp"

using namespace std;

int main() {

    char searchOption;
    char mazeOption;

    do {
        firstMenu();
        cin >> searchOption;

        switch(searchOption) {
            case '1':
                secondMenu();
                cin >> mazeOption;
                break;
            case '2':
                secondMenu();
                cin >> mazeOption;
                break;
            default:
                cout << "Opcão inválida. Digite novamente:" << endl << "> ";
                cin >> searchOption;
        }

        if(searchOption == '1' || searchOption == '2') {
            
        }

    } while(searchOption != '3');

    return 0;
}

void firstMenu() {

    cout << "Programa de Resolução de Labirintos" << endl;
    cout << "Selecione o método de busca desejado:" << endl;
    cout << "  1- Busca em profundidade iterativa;" << endl;
    cout << "  2- Busca A*." << endl;
    cout << "  3- Finalizar programa" << endl;
    cout << "> ";
}

void secondMenu() {

    cout << "Selecione o labirinto desejado:" << endl;
    cout << "  1- Labirinto 10x10;" << endl;
    cout << "  2- Labirinto 50x50;" << endl;
    cout << "  3- Labirinto 100x100;" << endl;
    cout << "  4- Labirinto 200x200." << endl;
    cout << "> ";
}