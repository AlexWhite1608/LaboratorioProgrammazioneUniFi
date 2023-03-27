#include <iostream>
#include <cstdlib>
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
              << "8: Visualizzare carrello\n" << std::endl;

    unsigned int action = 0;
    std::cin >> action;

    return action;
}

void actionManager(unsigned int action, ListManager* listManager, List* cart);
void actionManager(unsigned int action, ListManager* listManager, List* cart){

    switch (action) {
        case 1: {   // Creare una nuova lista1
            List* newList;
            std::string listName;

            std::cout << "Inserire il nome della lista da creare:" << std::endl;
            std::cin >> listName;

            newList = listManager->createList("ProductList", listName);
            std::cout << "E' stata creata la lista " << listManager->searchList(newList)->getName() << "!\n\n";
            break;
        }

        case 2: {   // Inserire un nuovo prodotto nella lista
            listManager->printLists();
            std::cout << "Selezionare la lista dove inserire il prodotto:" << std::endl;

            std::string selectedList;
            std::cin >> selectedList;

            List* list = listManager->searchList(selectedList);

            std::cout << "Hai scelto la lista " << selectedList << std::endl;

            std::cout << "\nInserire il nome del prodotto:" << std::endl;
            std::string name;
            std::cin >> name;

            std::cout << "\nInserire la categoria del prodotto:" << std::endl;
            std::string category;
            std::cin >> category;

            std::cout << "\nInserire la quantita' del prodotto:" << std::endl;
            unsigned int quantity;
            std::cin >> quantity;

            Product* product = new Product(name, category, quantity);
            list->addProduct(product);

            std::cout << name << " e' stato inserito nella lista " << selectedList << std::endl;
            break;
        }

        case 3: {   // Rimuovere un prodotto dalla lista
            listManager->printLists();
            std::cout << "Selezionare la lista dalla quale rimuovere il prodotto:" << std::endl;

            std::string selectedList;
            std::cin >> selectedList;

            List* list = listManager->searchList(selectedList);

            std::cout << "Hai scelto la lista " << selectedList << std::endl;
            list->printList();

            std::cout << "Inserire il nome del prodotto da rimuovere:" << std::endl;
            std::string name;
            std::cin >> name;

            Product* product = list->search(name);

            list->removeProduct(product);
            break;
        }

        case 4: {   // Aggiornare un prodotto della lista
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
            break;
        }

        case 5: {   // Inserire un prodotto nel carrello
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

            list->removeProduct(product);
            break;
        }

        case 6: {
            listManager->printLists();

            std::cout << "Selezionare la lista da visualizzare:" << std::endl;
            std::string selectList;
            std::cin >> selectList;

            List* list = listManager->searchList(selectList);

            if(list != nullptr)
                list->printList();

            break;
        }

        case 7: {
            listManager->printLists();

            std::cout << "Selezionare la lista da eliminare:" << std::endl;
            std::string selectedList;
            std::cin >> selectedList;

            listManager->removeList(selectedList);

            std::cout << selectedList << " e' stata rimossa!" << std::endl;
            break;
        }


        case 8: {
            std::cout << "Nel carrello ci sono i seguenti prodotti: " << std::endl;

            cart->printList();
            break;
        }

        default:
            break;
    }

}

//TODO: aggiungi i CLS e sistema grafica

int main() {
    ListManager* listManager = new ListManager();
    List* cart = listManager->createList("Cart", "");
    unsigned int action;

    do {

        action = actionList();
        actionManager(action, listManager, cart);

    } while (action != 0);

    return 0;
}
