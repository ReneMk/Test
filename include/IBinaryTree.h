#ifndef IBINARYTREE_H
#define IBINARYTREE_H

#include <Item.h>
#include <iostream>

#pragma once

class IBinaryTree
{
public:
    virtual void add(int value) = 0;
    virtual bool remove(int value) = 0;

    std::shared_ptr<Item> find(int value);
    void printTree();
    void removeTree(); 

protected:
    std::shared_ptr<Item> m_head;

private:
    void printTreePrivate(std::shared_ptr<Item> item);
    std::shared_ptr<Item> findPrivate(int value, std::shared_ptr<Item> item);
};

#endif