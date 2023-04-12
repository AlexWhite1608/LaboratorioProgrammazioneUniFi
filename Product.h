#ifndef LABORATORIOPROGRAMMAZIONE_PRODUCT_H
#define LABORATORIOPROGRAMMAZIONE_PRODUCT_H

#include <string>

class Product {
public:
    Product(const std::string &name, const std::string &category, unsigned int quantity);

    const std::string &getName() const;

    const std::string &getCategory() const;

    unsigned int getQuantity() const;

    void editName(const std::string& newName);

    void editQuantity(unsigned int newQuantity);

private:
    std::string name;
    std::string category;
    unsigned int quantity = 0;

};


#endif //LABORATORIOPROGRAMMAZIONE_PRODUCT_H
