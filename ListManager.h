//
// Created by aless on 22/11/2022.
//

#ifndef LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H
#define LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H

#include <list>
#include "List.h"

class ListManager {

    void createList(const std::string& listType, const std::string& listName);

    void removeList(List* list);

    void printList(List* list);

private:
    const List* searchList(List* list);

    std::list<List*> lists;
};


#endif //LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H
