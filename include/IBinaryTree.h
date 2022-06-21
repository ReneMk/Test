#ifndef IBINARYTREE_H
#define IBINARYTREE_H

#include "../include/Item.h"
#include <iostream>

#pragma once

class IBinaryTree
{
public:
    virtual void add(int value) = 0;
    virtual void add(std::shared_ptr<Item> newItem) = 0;
    virtual bool remove(int value) = 0;

    std::shared_ptr<Item> find(int value);
    void printTree();
    void removeTree();
    void printHead();

protected:
    std::shared_ptr<Item> m_head;
    void addPr(int value, std::shared_ptr<Item> memberOfTree);
    void addPr(std::shared_ptr<Item> newItem, std::shared_ptr<Item> memberOfTree);
    void changeHead();
    bool removePrivate(int value, std::shared_ptr<Item> item);
    std::shared_ptr<Item> leftEndFrom(std::shared_ptr<Item> item);

private:
    void printTreePrivate(std::shared_ptr<Item> item);
    std::shared_ptr<Item> findPrivate(int value, std::shared_ptr<Item> item);
};

#endif