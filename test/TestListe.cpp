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