//
// Created by aless on 22/11/2022.
//

#include <algorithm>
#include <iostream>
#include "ListManager.h"
#include "ProductList.h"
#include "Cart.h"

void ListManager::createList(const std::string &listType, const std::string& listName) {
    if (listType == "ProductList"){
        List* newList = new ProductList(listName);
        lists.push_back(newList);

    } else if (listType == "Cart"){
        List* newList = new Cart(listName);
        lists.push_back(newList);
    }
}

const List *ListManager::searchList(List *list) {
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

void ListManager::printList(List *list) {
    std::cout << "Le liste create dall'utente sono:" << std::endl;

    for(auto element : lists){
        std::cout << element->getName();
    }
}
