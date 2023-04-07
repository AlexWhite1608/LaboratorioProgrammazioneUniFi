#include "gtest/gtest.h"
#include "../List.h"
#include "../ListManager.h"

class TestProdotti : public ::testing::Test{
    void SetUp() override
    {
        listManager = new ListManager();
        list = listManager->createList("ProductList", "Test");
        cart = listManager->createList("Cart", "Carrello");
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
    List* cart = nullptr;

};


// Test: aggiungere un prodotto alla lista
TEST_F(TestProdotti, Inserimento){
    EXPECT_EQ(list->getNumberProducts(), 0);

    Product* product = new Product("TestProdotto", "TestCategoria", 1);
    listManager->addProduct(product, list);

    EXPECT_EQ(list->getNumberProducts(), 1);

}

// Test: rimozione prodotto dalla lista (quantità == 1)
TEST_F(TestProdotti, RimozioneUnitaria){
    Product* product = new Product("TestProdotto", "TestCategoria", 1);
    listManager->addProduct(product, list);

    EXPECT_EQ(list->getNumberProducts(), 1);

    listManager->removeProduct(product, list);

    EXPECT_EQ(list->getNumberProducts(), 0);

}

// Test: rimozione prodotto dalla lista (quantità > 1)
TEST_F(TestProdotti, RimozioneQuantita){
    Product* product = new Product("TestProdotto", "TestCategoria", 3);
    listManager->addProduct(product, list);

    EXPECT_EQ(list->getNumberProducts(), 1);
    EXPECT_EQ(listManager->searchProduct(product, list)->getQuantity(), 3);

    listManager->removeProduct(product, list);

    EXPECT_EQ(list->getNumberProducts(), 1);
    EXPECT_EQ(listManager->searchProduct(product, list)->getQuantity(), 2);

}

// Test: aggiornamento prodotto nella lista: (nome, quantità)
TEST_F(TestProdotti, Aggiornamento){
    Product* product = new Product("TestProdotto", "TestCategoria", 2);
    listManager->addProduct(product, list);

    product->editName("NuovoNome");
    product->editQuantity(3);

    EXPECT_EQ(product->getName(), "NuovoNome");
    EXPECT_EQ(product->getQuantity(), 3);
}

// Test: spostare un prodotto dalla lista al carrello
TEST_F(TestProdotti, AggiuntaCarrello){
    Product* product = new Product("TestProdotto", "TestCategoria", 1);

    listManager->addProduct(product, list);
    listManager->moveProductToCart(product, list, cart);

    EXPECT_EQ(list->getNumberProducts(), 0);
    EXPECT_EQ(cart->getNumberProducts(), 1);
}