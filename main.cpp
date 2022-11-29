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
            listManager->printLists();
            std::cout << "Selezionare la lista dove inserire il prodotto:" << std::endl;

            std::string selectedList;
            std::cin >> selectedList;

            List* list = listManager->searchList(selectedList);

            std::cout << "Hai scelto la lista " << selectedList << std::endl;

            std::cout << "Inserire il nome del prodotto:" << std::endl;
            std::string name;
            std::cin >> name;

            std::cout << "Inserire la categoria del prodotto:" << std::endl;
            std::string category;
            std::cin >> category;

            std::cout << "Inserire la quantità del prodotto:" << std::endl;
            unsigned int quantity;
            std::cin >> quantity;

            Product* product = new Product(name, category, quantity);
            list->addProduct(product);

            std::cout << name << " e' stato inserito nella lista " << selectedList << std::endl;

        } else if (selectedAction == 3) {               // Rimuovere un prodotto dalla lista

        } else if (selectedAction == 4) {               // Aggiornare un prodotto della lista

        } else if (selectedAction == 5) {               // Inserire un prodotto nel carrello

        } else if (selectedAction == 6) {               // Visualizzare una lista
            listManager->printLists();

            std::cout << "Selezionare la lista da visualizzare:" << std::endl;
            std::string selectList;
            std::cin >> selectList;

            List* list = listManager->searchList(selectList);

            if(list != nullptr)
                list->printList();

        } else if (selectedAction == 7) {               // Eliminare una lista
            listManager->printLists();

            std::cout << "Selezionare la lista da eliminare:" << std::endl;
            std::string selectedList;
            std::cin >> selectedList;

            listManager->removeList(selectedList);

            std::cout << selectedList << " e' stata rimossa!" << std::endl;

        } else if (selectedAction == 8) {               // Uscire
            exit(0);
        } else
            std::cout << "Errore";

    }


    return 0;
}
