#include <iostream>

unsigned int actionList();
unsigned int actionList() {
    std::cout << "Benvenuto! Che azione si desidera compiere?" << std::endl;

    std::cout << "1: Creare una nuova lista\n"
              << "2: Inserire un nuovo prodotto nella lista\n"
              << "3: Rimuovere un prodotto dalla lista\n"
              << "4: Aggiornare un prodotto della lista\n"
              << "5: Inserire un prodotto nel carrello\n"
              << "6: Visualizzare una lista\n"
              << "7: Eliminare una lista\n"
              << "8: Uscire\n" << std::endl;

    unsigned int action = 0;
    std::cin >> action;

    return action;
}

int main() {
    unsigned int selectedAction = 1;

    while (selectedAction > 0) {
        selectedAction = actionList();

        switch (selectedAction) {
            case 1:
                std::cout << "1";
                break;

            case 2:
                std::cout << "2";
                break;

            case 3:
                std::cout << "3";
                break;

            case 4:
                std::cout << "4";
                break;

            case 5:
                std::cout << "5";
                break;

            case 6:
                std::cout << "6";
                break;

            case 7:
                std::cout << "7";
                break;

            case 8:
                exit(0);

            default:
                std::cout << "ERRORE!" << std::endl;
        }
    }


    return 0;
}
