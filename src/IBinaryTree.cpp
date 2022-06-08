#include <IBinaryTree.h>


void IBinaryTree::printTree()
{
    printTreePrivate(m_head);
}

std::shared_ptr<Item> IBinaryTree::find(int value)
{
    return findPrivate(value, m_head);
}

void IBinaryTree::removeTree()
{
    m_head.reset();
}

std::shared_ptr<Item> IBinaryTree::findPrivate(int value, std::shared_ptr<Item> item)
{
    if (item == nullptr)
        return nullptr;
    if(value == item->getData()){
        return item;
    }
    std::shared_ptr<Item> ptr;
    if(value > item->getData()){
        ptr = findPrivate(value, item->m_left); 
    }else{
        ptr = findPrivate(value, item->m_right);
    }
    return ptr;
}

void IBinaryTree::printTreePrivate(std::shared_ptr<Item> item)
{
    if(item == nullptr)
        return;
    printTreePrivate(item->m_right);
    item->printData();
    std::cout<<" ";
    printTreePrivate(item->m_left);
}