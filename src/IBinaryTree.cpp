#include <IBinaryTree.h>
#include <iostream>

void IBinaryTree::add(int value)
{
    addPr(value, m_head);
}




void IBinaryTree::printTree()
{
    printTreePrivate(m_head);
}



void IBinaryTree::addPr(int value, std::shared_ptr<Item> item)
{
    // value > item->value   ide do lava
       
    if(item->value < value){
        if(item->m_left == nullptr){
            item->m_left = std::make_shared<Item>(value, m_head);
            return;
        }
        addPr(value,item->m_left);
        
    }else{
        if(item->m_right == nullptr){
            item->m_right = std::make_shared<Item>(value, m_head);
            return;
        }
        addPr(value,item->m_right);
        
    }
};

void IBinaryTree::printTreePrivate(std::shared_ptr<Item> item)
{
    if(item == nullptr)
        return;
    printTreePrivate(item->m_right);
    std::cout<< item->value << " ";
    printTreePrivate(item->m_left);
}





IBinaryTree::IBinaryTree(int val):m_head(std::make_shared<Item>(val,nullptr))
{
     
}








IBinaryTree::~IBinaryTree()
{

}