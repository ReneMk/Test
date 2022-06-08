#include <Nevyvazeny.h>
#include <Factory.h>


int main(int argc, char const *argv[])
{
    std::cout<< "Hello Test main" << std::endl;
    Nevyvazeny tree(5);
    Factory fac(10,20);

    std::cout<< std::endl<< "Factory values:" << std::endl;
    fac.printFactoryValues();
    std::cout<< std::endl;


    for (int i = 0; i < fac.items.size(); i++)
    {
        tree.add(fac.items[i]->getData());
    }

    std::cout<< std::endl << "Tree values:" << std::endl;
    tree.printTree();
    std::cout<< std::endl;

    int findNum = rand()% MAX_NUMBER;

    std::shared_ptr<Item> ptr = tree.find(findNum);

    if (ptr != nullptr)
    {
        std::cout<< "Find "<< ptr->getData() << std::endl;
    }else{
        std::cout<< "Did not find: " << findNum << std::endl;
    }

    ptr.reset();

    int removeNum = rand()% MAX_NUMBER;

    bool tmp = tree.remove(removeNum);

    if (tmp)
    {
        std::cout<< "Removed: " << removeNum <<std::endl;
    }else{
        std::cout<< "Did not find: " << removeNum << std::endl;
    }

    removeNum = rand()% MAX_NUMBER;
    tmp = tree.remove(removeNum);


    if (tmp)
    {
        std::cout<< "Removed: " << removeNum <<std::endl;
    }else{
        std::cout<< "Did not find: " << removeNum << std::endl;
    }

    std::cout<< std::endl << "Tree values:" << std::endl;
    tree.printTree();
    std::cout<< std::endl;


    tree.removeTree();
    std::cout<< std::endl << "Print Tree values after removeTree:" << std::endl;
    tree.printTree();

    std::cout<< std::endl << "Print Factory values after removeTree:" << std::endl;
    fac.printFactoryValues();
    std::cout<< std::endl;

    
    std::cout<<"Correct end" << std::endl;
    return 0;
}
