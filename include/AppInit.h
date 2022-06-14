#ifndef APPINIT_H
#define APPINIT_H

#include <Nevyvazeny.h>
#include <Vyvazeny.h>
#include <Factory.h>
#include <future>
#include <iostream>

#pragma once

class AppInit
{
public:
    AppInit(int numOfMembersInFactory, int seedForFactory = time(NULL));
    ~AppInit();
    void DoSomething(int input);

private:
    Factory m_factory;
    Vyvazeny m_BinaryTree;

    void printFactory();
    void printBinaryTree();
    void addItem(int value);
    bool findItemFromBinaryTree(int value);
    bool deleteItemFromTree(int value);
};

#endif