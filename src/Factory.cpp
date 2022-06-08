#include "Factory.h"

Factory::Factory(int seed, int numOfItems)
{
    items.clear();
    //items.resize(numOfItems);
    createDataVector(seed, numOfItems);
}

Factory::~Factory()
{
    
}

std::shared_ptr<Item> Factory::createItem(int value)
{
    return std::make_shared<Item>(value, nullptr);
}

void Factory::createDataVector(int seed, int numOfItems)
{
    int tmp;
    srand(seed);
    for (int i = 0; i < numOfItems; i++)
    {
        tmp = (rand() % (MAX_NUMBER+1));
        items.push_back(std::make_shared<Item>(tmp, nullptr));
    }
    
}

void Factory::printFactoryValues(){
    for (std::shared_ptr<Item> i : items) 
    {
        std::cout << i->getData() << " ";
    }
    std::cout << std::endl;
}