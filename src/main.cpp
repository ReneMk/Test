#include <AppInit.h>

template <class T>
void TestFindValue(T tree)
{
    int findNum = rand() % MAX_NUMBER;

    auto ptr = tree.find(findNum);

    if (ptr != nullptr)
    {
        std::cout << "Find " << ptr->getData() << std::endl;
    }
    else
    {
        std::cout << "Did not find: " << findNum << std::endl;
    }
}

template <class T>
void TestRemoveValue(T tree)
{
    int removeNum = rand() % MAX_NUMBER;
    bool tmp = tree.remove(removeNum);

    if (tmp)
    {
        std::cout << "Removed: " << removeNum << std::endl;
    }
    else
    {
        std::cout << "Did not find: " << removeNum << std::endl;
    }
}

void printFac(Factory fac)
{
    std::cout << std::endl
              << "Factory values:" << std::endl;
    fac.printFactoryValues();
    std::cout << std::endl;
}

template <class T>
void printTree(T tree)
{
    std::cout << std::endl
              << "Tree values:" << std::endl;
    tree.printTree();
    std::cout << std::endl;
}

/*
-----------------------------------------------------------
-----------------------------------------------------------
-----------------------------------------------------------
-----------------------------------------------------------
-----------------------------------------------------------
-----------------------------------------------------------
-----------------------------------------------------------
*/


#define TypeOfTree Vyvazeny

int main(int argc, char const *argv[])
{
   // std::cout << "Hello Test main" << std::endl;

     AppInit app(1500);
     app.DoSomething(0);
     app.DoSomething(0);
     app.DoSomething(3);
     app.DoSomething(3);
     app.DoSomething(3);
     app.DoSomething(3);
     app.DoSomething(1);

    return 0;
}