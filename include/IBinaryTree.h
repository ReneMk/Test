#ifndef IBINARYTREE_H
#define IBINARYTREE_H

#include <Item.h>

#pragma once

class IBinaryTree
{
public:
    IBinaryTree(int val);
    ~IBinaryTree();

    std::shared_ptr<Item> m_head;


    void add(int value);
    bool remove();
    void printTree();

private:
    void addPr(int value, std::shared_ptr<Item> item);
    void printTreePrivate(std::shared_ptr<Item> item);
};

#endif