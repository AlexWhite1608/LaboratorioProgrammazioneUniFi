//
// Created by aless on 22/11/2022.
//

#include <algorithm>
#include <iostream>
#include "ListManager.h"
#include "ProductList.h"
#include "Cart.h"

List* ListManager::createList(const std::string &listType, const std::string& listName) {
    List* newList;
    if (listType == "ProductList"){
        newList = new ProductList(listName);
        lists.push_back(newList);

    } else if (listType == "Cart"){
        newList = new Cart(listName);
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

void ListManager::printLists() {
    std::cout << "Le liste create dall'utente sono:" << std::endl;

    for(auto element : lists){
        std::cout << element->getName() << std::endl;
    }
}

List *ListManager::searchList(const std::string &name) {
    for(auto i : lists){
        if (i->getName() == name)
            return i;
    }

    return nullptr;
}
