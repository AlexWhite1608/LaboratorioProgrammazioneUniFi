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

// Test: ricerca di una lista
TEST_F(TestListe, RicercaLista){
    auto list1 = listManager->createList("ProductList", "ListaProva1");
    auto list2 = listManager->createList("ProductList", "ListaProva2");

    EXPECT_EQ(listManager->getLists().size(), 2);

    auto findList1 = listManager->searchList("ListaProva1");
    auto findList2 = listManager->searchList(list2);

    EXPECT_EQ(list2, findList2);
    EXPECT_EQ(list1, findList1);
}