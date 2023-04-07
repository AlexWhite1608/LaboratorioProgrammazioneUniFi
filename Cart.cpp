#include <iostream>
#include "Cart.h"

Cart::Cart(const std::string &name) : List(name) {}

void Cart::printList() {
    if(products.empty())
        std::cout << "Carrello vuoto!" << std::endl;

    for(auto i : products){
        std::cout << "\nNome prodotto: " << i->getName() << std::endl
                  << "Categoria: " << i->getCategory() << std::endl
                  << "Quantita': " << i->getQuantity() << std::endl
                  << "-------------- " << std::endl;
    }
}
