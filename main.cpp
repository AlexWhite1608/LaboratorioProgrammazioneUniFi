#include <iostream>
#include "ListManager.h"

unsigned int actionList();
unsigned int actionList() {
    std::cout << "Che azione si desidera compiere?" << std::endl;

    std::cout << "1: Creare una nuova lista\n"
              << "2: Inserire un nuovo prodotto nella lista\n"
              << "3: Rimuovere un prodotto dalla lista\n"
              << "4: Aggiornare un prodotto della lista\n"
              << "5: Inserire un prodotto nel carrello\n"
              << "6: Visualizzare una lista\n"
              << "7: Eliminare una lista\n"
              << "8: Visualizzare carrello\n"
              << "9: Uscire\n" << std::endl;

    unsigned int action = 0;
    std::cin >> action;

    return action;
}

int main() {
    unsigned int selectedAction = 1;
    ListManager* listManager = new ListManager();
    List* cart = listManager->createList("Cart", "");


    while (selectedAction > 0) {
        selectedAction = actionList();

        // ------------------
        // Creare una nuova lista
        // ------------------
        if (selectedAction == 1) {
            List* newList;
            std::string listName;

            std::cout << "Inserire il nome della lista da creare:" << std::endl;
            std::cin >> listName;

            newList = listManager->createList("ProductList", listName);
            std::cout << "E' stata creata la lista " << listManager->searchList(newList)->getName() << "!\n\n";

        // ------------------
        // Inserire un nuovo prodotto nella lista
        // ------------------
        } else if (selectedAction == 2) {
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

            std::cout << "Inserire la quantita' del prodotto:" << std::endl;
            unsigned int quantity;
            std::cin >> quantity;

            Product* product = new Product(name, category, quantity);
            list->addProduct(product);

            std::cout << name << " e' stato inserito nella lista " << selectedList << std::endl;

        // ------------------
        // Rimuovere un prodotto dalla lista
        // ------------------
        } else if (selectedAction == 3) {
            listManager->printLists();
            std::cout << "Selezionare la lista dalla quale rimuovere il prodotto:" << std::endl;

            std::string selectedList;
            std::cin >> selectedList;

            List* list = listManager->searchList(selectedList);

            std::cout << "Hai scelto la lista " << selectedList << std::endl;
            list->printList();

            std::cout << "\nInserire il nome del prodotto da rimuovere:" << std::endl;
            std::string name;
            std::cin >> name;

            Product* product = list->search(name);

            if(product != nullptr){
                list->removeProduct(product);
            } else
                std::cout << "Il prodotto non e' presente nella lista!\n" << std::endl;

        // ------------------
        // Aggiornare un prodotto della lista
        // ------------------
        } else if (selectedAction == 4) {
            listManager->printLists();

            std::cout << "Selezionare la lista dove e' presente il prodotto:\n" << std::endl;
            std::string selectedList;
            std::cin >> selectedList;

            List* list = listManager->searchList(selectedList);

            std::cout << "Selezionare il prodotto che si vuole modificare:\n" << std::endl;

            list->printList();
            std::string selectedProduct;
            std::cin >> selectedProduct;

            Product* product = list->search(selectedProduct);

            if(list == nullptr || product == nullptr){
                std::cout << "Errore!";
                exit(1);
            }

            std::cout << "\n\nCosa si vuole modificare: " << std::endl
                      << "1: Nome\n"
                      << "2: Quantita'" << std::endl;

            int edit;
            std::cin >> edit;

            unsigned int newQty;
            std::string newName;

            switch (edit) {
                case 1:     //Nome
                    std::cout << "\nInserire il nuovo nome del prodotto: " << std::endl;
                    std::cin >> newName;

                    product->editName(newName);

                break;

                case 2:     //Quantità
                    std::cout << "\nInserire la nuova quantita' del prodotto: " << std::endl;
                    std::cin >> newQty;

                    product->editQuantity(newQty);

                    std::cout << "\nQuantita' aggiornata!" << std::endl;
                break;

                default:
                    std::cout << "\nErrore!";
                    exit(1);
            }

        // ------------------
        // Inserire un prodotto nel carrello
        // ------------------
        } else if (selectedAction == 5) {
            listManager->printLists();

            std::cout << "Selezionare la lista dove e' presente il prodotto:\n" << std::endl;
            std::string selectedList;
            std::cin >> selectedList;

            List* list = listManager->searchList(selectedList);

            std::cout << "Selezionare il prodotto che si vuole inserire:\n" << std::endl;

            list->printList();
            std::string selectedProduct;
            std::cin >> selectedProduct;

            Product* product = list->search(selectedProduct);

            cart->addProduct(product);
            std::cout << selectedProduct << " e' stato aggiunto al carrello!" << std::endl;

            //TODO: se inserito nel carrello il prodotto va rimosso dalla rispettiva lista


        // ------------------
        // Visualizzare una lista
        // ------------------
        } else if (selectedAction == 6) {
            listManager->printLists();

            std::cout << "Selezionare la lista da visualizzare:" << std::endl;
            std::string selectList;
            std::cin >> selectList;

            List* list = listManager->searchList(selectList);

            if(list != nullptr)
                list->printList();

        // ------------------
        // Eliminare una lista
        // ------------------
        } else if (selectedAction == 7) {
            listManager->printLists();

            std::cout << "Selezionare la lista da eliminare:" << std::endl;
            std::string selectedList;
            std::cin >> selectedList;

            listManager->removeList(selectedList);

            std::cout << selectedList << " e' stata rimossa!" << std::endl;

        // ------------------
        // Visualizzare il carrello
        // ------------------
        } else if (selectedAction == 8) {
            std::cout << "Nel carrello ci sono i seguenti prodotti: " << std::endl;

            cart->printList();

        // ------------------
        // Uscire
        // ------------------
        } else if (selectedAction == 9) {
            exit(0);

        } else
            std::cout << "Errore";
    }

    return 0;
}
