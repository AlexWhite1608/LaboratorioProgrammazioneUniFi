#ifndef LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H
#define LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H

#include <list>
#include "List.h"

class ListManager{

public:
    List* createList(const std::string& listType, const std::string& listName);

    void removeList(List* list);

    List* searchList(List* list);

    List* searchList(const std::string& name);

    const std::list<List *> &getLists() const;

    void addProduct(Product* product, List* list);

    void removeProduct(Product* product, List* list);

    Product *searchProduct(Product* product, List* list);

    void moveProductToCart(Product* product, List* list, List* cart);

private:
    std::list<List*> lists;
};


#endif //LABORATORIOPROGRAMMAZIONE_LISTMANAGER_H
