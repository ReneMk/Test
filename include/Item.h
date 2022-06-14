#ifndef ITEM_H
#define ITEM_H

#include <memory>
#include <iostream>

#pragma once

class Item
{
public:
    Item(int val, std::shared_ptr<Item> parent);
    Item(const Item &pItem);
    ~Item();

    std::shared_ptr<Item> m_left;
    std::shared_ptr<Item> m_right;
    std::weak_ptr<Item> m_parent;

    int getData();
    void printData();
    void setValue(int value);

private:
    int m_value;
};

#endif