#ifndef FACTORY_H
#define FACTORY_H

#pragma once

#include <Item.h>
#include <vector>
#include <stdlib.h>

#define MAX_NUMBER 1000

class Factory
{
public:
    Factory(int seed, int numOfItems);
    ~Factory();
    void createDataVector(int seed, int numOfItems);
    std::shared_ptr<Item> createItem(int value);
    std::vector<std::shared_ptr<Item>> items;
    void printFactoryValues();
private:

};

#endif