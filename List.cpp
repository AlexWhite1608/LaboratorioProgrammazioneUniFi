//
// Created by aless on 22/11/2022.
//

#include "List.h"

List::List(const std::string &name) : name(name) {}

const std::string &List::getName() const {
    return name;
}
