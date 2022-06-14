#include <Item.h>

Item::Item(int val, std::shared_ptr<Item> parent) : m_value(val), m_parent(parent) {}

Item::Item(const Item &pItem) : m_value(pItem.m_value), m_left(nullptr), m_right(nullptr) {}

Item::~Item() {}

int Item::getData()
{
    return m_value;
}

void Item::printData()
{
    std::cout << m_value;
}

void Item::setValue(int value)
{
    m_value = value;
}