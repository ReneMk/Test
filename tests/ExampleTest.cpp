
#include <gtest/gtest.h>

#include "../include/AppInit.h"


struct InitFacAndVyvBinTree : public testing::Test
{
    int numOfItemAtBegining = 50;
    Factory fac;
    Vyvazeny binTree;

    void SetUp()
    {
        fac.createDataVector(100, numOfItemAtBegining);
        for (int i = 0; i < numOfItemAtBegining; i++)
        {
            binTree.add(fac.getItem(i));
        }
    }
    void TearDown(){}
};

TEST_F(InitFacAndVyvBinTree, AddingToBinTreeFromFac ) 
{ 
    int index = 0;
    auto ptr = binTree.find(fac.getValue(index));

    EXPECT_EQ(ptr->getData(),fac.getValue(index));
}



TEST(StartTest, MacroTest)
{
    Item a(10, nullptr);
    Item b(10,nullptr);
    EXPECT_EQ(a.getData(),b.getData());
}


TEST(SecondTest, TestForItem)
{
    ASSERT_EQ(4,4);
    EXPECT_EQ(3,3);
}
