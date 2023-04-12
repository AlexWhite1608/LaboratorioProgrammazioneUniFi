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

void ListManager::moveProductToCart(Product *product, List *list, List *cart) {
    list->removeProduct(product);
    cart->addProduct(product);
}

void ListManager::addProduct(Product *product, List *list) {
    return list->addProduct(product);
}

void ListManager::removeProduct(Product *product, List *list) {
    return list->removeProduct(product);
}

Product *ListManager::searchProduct(Product *product, List *list) {
    return list->searchProduct(product);
}
