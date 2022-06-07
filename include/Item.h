#ifndef ITEM_H
#define ITEM_H

#include <memory>

#pragma once

class Item
{
public:
    Item(int val, std::shared_ptr<Item> parent);
    
    ~Item();
    int value;
    std::shared_ptr<Item> m_left;
    std::shared_ptr<Item> m_right;
    std::weak_ptr<Item> m_parent;
    
    
private:

};

#endif