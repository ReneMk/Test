#ifndef FACTORY_H
#define FACTORY_H

#pragma once

#include "../include/Item.h"
#include <vector>
#include <stdlib.h>

#define MAX_NUMBER 1000
#define SPACE_FOR_NEW_ELEMENTS 3

class Factory
{
public:
    Factory(int seed, int numOfItems);
    Factory();
    ~Factory();
    void createDataVector(int seed, int numOfItems);
    std::shared_ptr<Item> createItem(int value);
    void printFactoryValues();
    int numOfItems();
    int capacityOfItems();
    void resizeSpaceInItems(int newSpace = SPACE_FOR_NEW_ELEMENTS);
    int getValue(int index);
    std::shared_ptr<Item> getItem(int index);
    void setValue(int index, int value);
    void addItem(int value);

private:
    std::vector<std::shared_ptr<Item>> m_items;
};

#endif