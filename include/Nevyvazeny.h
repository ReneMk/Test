#ifndef NEVYVAZENY_H
#define NEVYVAZENY_H

#pragma once

#include <IBinaryTree.h>
#include <memory>

class Nevyvazeny : public IBinaryTree
{
public:
    Nevyvazeny(int value);
    Nevyvazeny();
    ~Nevyvazeny();
    void add(int value);
    void add(std::shared_ptr<Item> newItem);
    bool remove(int value);
};

#endif