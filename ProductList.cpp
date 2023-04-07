#include <iostream>
#include "ProductList.h"

ProductList::ProductList(const std::string &name) : List(name) {}

void ProductList::printList() {
    if(products.empty())
        std::cout << "Lista vuota!" << std::endl;

    for(auto i : products){
        std::cout << "\nNome prodotto: " << i->getName() << std::endl
                  << "Categoria: " << i->getCategory() << std::endl
                  << "Quantita': " << i->getQuantity() << std::endl
                  << "-------------- " << std::endl;
    }
}
