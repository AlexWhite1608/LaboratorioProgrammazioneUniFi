#include <iostream>
#include "ListManager.h"

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
    ListManager* listManager = new ListManager();


    while (selectedAction > 0) {
        selectedAction = actionList();

        if (selectedAction == 1) {          // Creare una nuova lista
            List* newList;
            std::string listName;

            std::cout << "Inserire il nome della lista da creare:" << std::endl;

            std::cin >> listName;

            newList = listManager->createList("ProductList", listName);

            std::cout << "E' stata creata la lista " << listManager->searchList(newList)->getName() << "!\n";

        } else if (selectedAction == 2) {               // Inserire un nuovo prodotto nella lista

        } else if (selectedAction == 3) {               // Rimuovere un prodotto dalla lista

        } else if (selectedAction == 4) {               // Aggiornare un prodotto della lista

        } else if (selectedAction == 5) {               // Inserire un prodotto nel carrello

        } else if (selectedAction == 6) {               // Visualizzare una lista

        } else if (selectedAction == 7) {               // Eliminare una lista

        } else if (selectedAction == 8) {               // Uscire
            exit(0);
        } else
            std::cout << "Errore";

    }


    return 0;
}
