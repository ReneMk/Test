#include "../include/AppInit.h"

AppInit::AppInit(int numOfMembersInFactory, int seedForFactory) : m_factory(seedForFactory, numOfMembersInFactory)
{
    for (int i = 0; i < numOfMembersInFactory; i++)
    {
        m_BinaryTree.add(m_factory.getItem(i));
    }
}

AppInit::~AppInit() {}

void AppInit::printFactory()
{
    std::cout << std::endl
              << "Factory values:" << std::endl;
    m_factory.printFactoryValues();
    std::cout << std::endl;
}

void AppInit::printBinaryTree()
{
    std::cout << std::endl
              << "Binary Tree values:" << std::endl;
    m_BinaryTree.printTree();
    std::cout << std::endl;
}

void AppInit::addItem(int value)
{
    m_factory.addItem(value);
    m_BinaryTree.add(m_factory.getItem(m_factory.numOfItems() - 1));
}

bool AppInit::findItemFromBinaryTree(int value)
{
    auto ptr = m_BinaryTree.find(value);

    if (ptr != nullptr)
    {
        std::cout << "Find " << ptr->getData() << std::endl;
        return true;
    }
    else
    {
        std::cout << "Did not find: " << value << std::endl;
        return false;
    }
}

bool AppInit::deleteItemFromTree(int value)
{
    return m_BinaryTree.remove(value);
}
/*
0 find item
1 print
2 remove
3 add
*/
void AppInit::DoSomething(int input)
{
    srand(time(NULL));
    int tmp = (rand() % (MAX_NUMBER + 1));
/*
    std::future<bool> asyncFun1;
    std::future<bool> asyncFun2;
    std::future<bool> asyncFun3;
    std::future<bool> asyncFun4;*/
    switch (input)
    {
    // find item
    case 0:
      /*  std::cout << "Finding: " << tmp << std::endl;
        asyncFun1 = std::async(&AppInit::findItemFromBinaryTree, this, tmp);
        tmp = (rand() % (MAX_NUMBER + 1));
        asyncFun2 = std::async(&AppInit::findItemFromBinaryTree, this, tmp);
        std::cout << "Finding: " << tmp << std::endl;
        tmp = (rand() % (MAX_NUMBER + 1));
        asyncFun3 = std::async(&AppInit::findItemFromBinaryTree, this, tmp);
        std::cout << "Finding: " << tmp << std::endl;
        tmp = (rand() % (MAX_NUMBER + 1));
        asyncFun4 = std::async(&AppInit::findItemFromBinaryTree, this, tmp);
        std::cout << "Finding: " << tmp << std::endl;

        asyncFun1.wait();
        asyncFun2.wait();
        asyncFun3.wait();
        asyncFun4.wait();*/
        break;
    // print item
    case 1:
        printFactory();
        printBinaryTree();

        break;
    // remove item
    case 2:
        tmp = rand() % (MAX_NUMBER + 1);
        std::cout << "Removing: " << tmp << std::endl;
        deleteItemFromTree(tmp);
        break;
    // add item
    case 3:
        tmp = rand() % (MAX_NUMBER + 1);
        std::cout << "Adding: " << tmp << std::endl;
        addItem(tmp);
        break;

    default:
        break;
    }
}