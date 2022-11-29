//
// Created by aless on 22/11/2022.
//

#ifndef LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H
#define LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H

#include <list>
#include "List.h"

class ListManager {

public:
    List* createList(const std::string& listType, const std::string& listName);

    void removeList(List* list);

    void printLists();

    List* searchList(List* list);

    List* searchList(const std::string& name);

private:
    std::list<List*> lists;
};


#endif //LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H
