#ifndef LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H
#define LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H

#include <list>
#include "List.h"

class ListManager {

public:
    List* createList(const std::string& listType, const std::string& listName);

    void removeList(List* list);

    void removeList(const std::string& name);

    void printLists();

    List* searchList(List* list);

    List* searchList(const std::string& name);

    const std::list<List *> &getLists() const;

private:
    std::list<List*> lists;
};


#endif //LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H
