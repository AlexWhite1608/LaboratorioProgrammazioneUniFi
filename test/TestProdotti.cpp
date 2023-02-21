//
// Created by aless on 16/02/2023.
//

#include "gtest/gtest.h"
#include "../List.h"
#include "../ListManager.h"
#include "../Product.h"

// Test: creare una nuova lista ed aggiungere un prodotto

TEST(TestProdotti, CreazioneEInserimento){
    ListManager* listManager = new ListManager();
    List* list = listManager->createList("ProductList", "Test");

    EXPECT_EQ(list->getProducts().size(), 0);

    Product* product = new Product("TestProdotto", "TestCategoria", 1);
    list->addProduct(product);

    EXPECT_EQ(list->getProducts().size(), 1);

}