#include <iostream>

#include <IBinaryTree.h>





int main(int argc, char const *argv[])
{
    std::cout<< "Hello World!" << std::endl;
    IBinaryTree tree(5);
    //Item pom(3,tree.m_head);
    //tree.m_head->m_right = std::make_shared<Item>(3,tree.m_head);
    tree.add(3);

    tree.add(100);

    tree.add(7);

    tree.add(6);
    
    tree.printTree();
    std::cout<< std::endl;
    
    return 0;
}
