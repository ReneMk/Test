#ifndef ITEM_H
#define ITEM_H

#include <memory>
#include <iostream>

#pragma once

class Item
{
public:
    Item(int val, std::shared_ptr<Item> parent);
    
    ~Item();
    
    std::shared_ptr<Item> m_left;
    std::shared_ptr<Item> m_right;
    std::weak_ptr<Item> m_parent;
    
    int getData();
    void printData();

    
private:
    int value;

};

#endif