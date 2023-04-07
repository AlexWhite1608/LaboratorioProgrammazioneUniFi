#include <algorithm>
#include <iostream>
#include "ListManager.h"
#include "ProductList.h"
#include "Cart.h"

List* ListManager::createList(const std::string &listType, const std::string& listName = "") {
    List* newList;
    if (listType == "ProductList"){
        newList = new ProductList(listName);
        lists.push_back(newList);

    } else if (listType == "Cart"){
        newList = new Cart("Carrello");
        lists.push_back(newList);
    }

    else
        newList = nullptr;

    return newList;
}

List *ListManager::searchList(List *list) {
    for(auto & i : lists){
        if (i == list)
            return i;
    }

    return nullptr;
}

void ListManager::removeList(List *list) {
    if (searchList(list) != nullptr)
        lists.remove(list);
    else
        std::cout << list->getName() << " non esiste!" << std::endl;
}

List *ListManager::searchList(const std::string &name) {
    for(auto i : lists){
        if (i->getName() == name)
            return i;
    }

    return nullptr;
}

const std::list<List *> &ListManager::getLists() const {
    return lists;
}

void ListManager::addProduct(Product* product, List* list) {
    if(searchProduct(product, list) != nullptr){
        for(auto product_ : list->getProducts()){
            if(product_->getName() == product->getName()){
                product_->editQuantity(product_->getQuantity() + 1);
                std::cout << "Il prodotto e' gia' presente, aumentata la quantita'!" << std::endl;
            }
        }
    } else
        list->getProducts().push_back(product);
}

void ListManager::removeProduct(Product *product, List* list) {
    if(searchProduct(product, list) != nullptr){
        for(auto product_ : list->getProducts()){
            if(product_->getName() == product->getName()){
                if(product_->getQuantity() > 1){
                    product_->editQuantity(product_->getQuantity() - 1);
                    break;
                } else if (product_->getQuantity() == 1){
                    list->getProducts().remove(product);
                    break;
                }
            }
        }
    } else
        std::cout << product->getName() << " non è presente nella lista!" << std::endl;
}

Product *ListManager::searchProduct(Product *product, List* list) {
    for(auto& i : list->getProducts()){
        if (i == product)
            return i;
    }

    return nullptr;
}

void ListManager::moveProductToCart(Product *product, List *list, List *cart) {
    this->removeProduct(product, list);
    this->addProduct(product, cart);
}
