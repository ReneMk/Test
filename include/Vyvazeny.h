#ifndef VYVAZENY_H
#define VYVAZENY_H

#pragma once

#include <IBinaryTree.h>

class Vyvazeny : public IBinaryTree
{
public:
    Vyvazeny();
    Vyvazeny(int value);
    ~Vyvazeny();

    void add(int value);
    void add(std::shared_ptr<Item> item);
    bool remove(int value);

private:
    int height(std::shared_ptr<Item> item);
    int diferent(std::shared_ptr<Item> item);
    void balance(std::shared_ptr<Item> item);
    std::shared_ptr<Item> rr_Rotation(std::shared_ptr<Item> item_root);
    std::shared_ptr<Item> ll_Rotation(std::shared_ptr<Item> item_root);
    std::shared_ptr<Item> lr_Rotation(std::shared_ptr<Item> item_root);
    std::shared_ptr<Item> rl_Rotation(std::shared_ptr<Item> item_root);
};

#endif