//
// Created by aless on 16/02/2023.
//

#include "gtest/gtest.h"
#include "../List.h"
#include "../ListManager.h"

class TestProdotti : public ::testing::Test{
    void SetUp() override
    {
        listManager = new ListManager();
        list = listManager->createList("ProductList", "Test");
    }

    void TearDown() override {
        delete listManager;
        delete list;
        listManager = nullptr;
        list = nullptr;
    }

protected:
    ListManager* listManager = nullptr;
    List* list = nullptr;

};


// Test: aggiungere un prodotto alla lista
TEST_F(TestProdotti, Inserimento){
    EXPECT_EQ(list->getProducts().size(), 0);

    Product* product = new Product("TestProdotto", "TestCategoria", 1);
    list->addProduct(product);

    EXPECT_EQ(list->getProducts().size(), 1);

}

// Test: rimozione prodotto dalla lista (quantità == 1)
TEST_F(TestProdotti, Rimozione){
    Product* product = new Product("TestProdotto", "TestCategoria", 1);
    list->addProduct(product);

    EXPECT_EQ(list->getProducts().size(), 1);

    list->removeProduct(product);

    EXPECT_EQ(list->getProducts().size(), 0);

}

// Test: rimozione prodotto dalla lista (quantità > 1)
TEST_F(TestProdotti, RimozioneQuantita){
    Product* product = new Product("TestProdotto", "TestCategoria", 3);
    list->addProduct(product);

    EXPECT_EQ(list->getProducts().size(), 1);
    EXPECT_EQ(list->search(product)->getQuantity(), 3);

    list->removeProduct(product);

    EXPECT_EQ(list->getProducts().size(), 1);
    EXPECT_EQ(list->search(product)->getQuantity(), 2);

}