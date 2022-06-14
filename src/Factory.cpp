#include "Factory.h"

Factory::Factory(int seed, int numOfItems)
{
    m_items.resize(numOfItems + SPACE_FOR_NEW_ELEMENTS);
    createDataVector(seed, numOfItems);
    int tmp = m_items.size();
    for (int i = tmp - SPACE_FOR_NEW_ELEMENTS; i < tmp; i++)
    {
        m_items.pop_back();
    }
}

Factory::~Factory()
{
}

std::shared_ptr<Item> Factory::createItem(int value)
{
    return std::make_shared<Item>(value, nullptr);
}

void Factory::setValue(int index, int value)
{
    m_items[index]->setValue(value);
}

void Factory::createDataVector(int seed, int numOfItems)
{
    int tmp;
    srand(seed);
    for (int i = 0; i < numOfItems; i++)
    {
        tmp = (rand() % (MAX_NUMBER + 1));
        m_items[i] = (std::make_shared<Item>(tmp, nullptr));
    }
}

void Factory::printFactoryValues()
{
    for (std::shared_ptr<Item> i : m_items)
    {
        std::cout << i->getData() << " ";
    }
    std::cout << std::endl;
}

int Factory::numOfItems()
{
    return m_items.size();
}

int Factory::capacityOfItems()
{
    return m_items.capacity();
}

int Factory::getValue(int index)
{
    return m_items[index]->getData();
}

std::shared_ptr<Item> Factory::getItem(int index)
{
    return m_items[index];
}

void Factory::resizeSpaceInItems(int addNewSpace)
{
    int tmp = m_items.size();
    m_items.resize(tmp + addNewSpace);
    for (int i = tmp; i < tmp + addNewSpace; i++)
    {
        m_items.pop_back();
    }
}

void Factory::addItem(int value)
{
    if (numOfItems() == capacityOfItems())
    {
        resizeSpaceInItems();
    }
    m_items.push_back(std::make_shared<Item>(value, nullptr));
}