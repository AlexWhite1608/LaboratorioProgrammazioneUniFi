//
// Created by aless on 22/11/2022.
//

#ifndef LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H
#define LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H

#include <list>
#include "list.h"

class ListManager {
    bool addList();

    bool removeList();

private:
    std::list<List*> lists;
};


#endif //LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H
