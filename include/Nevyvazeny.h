#ifndef NEVYVAZENY_H
#define NEVYVAZENY_H

#pragma once

#include <IBinaryTree.h>
#include <memory>

class Nevyvazeny : public IBinaryTree
{
public:
    Nevyvazeny(int value);
    ~Nevyvazeny();
    void add(int value);
    bool remove(int value);
private:
    void addPr(int value, std::shared_ptr<Item> item);
    bool removePrivate(int value, std::shared_ptr<Item> item);
    std::shared_ptr<Item> leftEndFrom(std::shared_ptr<Item> item);
    void changeHead();
};

#endif