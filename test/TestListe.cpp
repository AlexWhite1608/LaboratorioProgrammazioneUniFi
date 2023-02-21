#include "gtest/gtest.h"
#include "../List.h"
#include "../ListManager.h"

class TestListe : public ::testing::Test{
    void SetUp() override
    {
        listManager = new ListManager();
    }

    void TearDown() override {
        delete listManager;
        listManager = nullptr;
    }

protected:
    ListManager* listManager = nullptr;
};

// Test: creare una nuova lista
TEST_F(TestListe, CreazioneLista){
    listManager->createList("ProductList", "ListaProva");

    EXPECT_EQ(listManager->getLists().size(), 1);
}

// Test: rimuovere una lista
TEST_F(TestListe, RimozioneLista){
    auto list = listManager->createList("ProductList", "ListaProva");

    EXPECT_EQ(listManager->getLists().size(), 1);

    listManager->removeList(list);

    EXPECT_EQ(listManager->getLists().size(), 0);
}