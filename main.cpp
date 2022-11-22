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

            case 2:

            case 3:

            case 4:

            case 5:

            case 6:

            case 7:

            case 8:
                exit(0);

            default:
                std::cout << "ERRORE!" << std::endl;
        }
    }


    return 0;
}
