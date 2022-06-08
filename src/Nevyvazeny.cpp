#include <Nevyvazeny.h>


Nevyvazeny::Nevyvazeny(int value)//: m_head(std::make_shared<Item>(value,nullptr))
{
    m_head = (std::make_shared<Item>(value,nullptr));
}

Nevyvazeny::~Nevyvazeny()
{
    removeTree();
}

void Nevyvazeny::add(int value)
{
    addPr(value, m_head);
}

bool Nevyvazeny::remove(int value)
{
    return removePrivate(value, m_head);
}

void Nevyvazeny::changeHead()
{
    std::shared_ptr<Item> item = m_head;
    m_head.reset();
    if (item->m_right == nullptr)
    {
        if (item->m_left != nullptr)
        {
            m_head = item->m_left;
        }
        return;
    }
    m_head = item->m_right;
    std::shared_ptr<Item> ptr = leftEndFrom(item->m_right);
    ptr->m_left = item->m_left;

    return;
}

bool Nevyvazeny::removePrivate(int value, std::shared_ptr<Item> item)
{ 
    if (item == m_head)
    {
        changeHead();
        return true; 
    }

    if(item == nullptr || (item->m_left == nullptr && item->m_right == nullptr)) 
    {
        return false;
    }

    bool tmp = false; 

    if (item->m_left != nullptr && item->m_left->getData() == value)
    {
        std::shared_ptr<Item> ptr = item->m_left;
        item->m_left.reset();

        if (ptr->m_right == nullptr)
        {
            item->m_left = ptr->m_left;
            return true;
        }
        item->m_left = ptr->m_right;

        std::shared_ptr<Item> ptrTmp = leftEndFrom(item->m_left);
        ptrTmp->m_left = ptr->m_left;

      //  ptr.reset();
      //  ptrTmp.reset();

        return true;
    }

    if (item->m_right != nullptr && item->m_right->getData() == value)
    {
        std::shared_ptr<Item> ptr = item->m_right;
        item->m_right.reset();
        if (ptr->m_right == nullptr)
        {
            item->m_right = ptr->m_left;
            return true;
        }
        item->m_right = ptr->m_right;

        std::shared_ptr<Item> ptrTmp = leftEndFrom(item->m_right);
        ptrTmp->m_left = ptr->m_left;

        // podla valgrindu by to malo byt OK
        //ptr.reset();
       // ptrTmp.reset();

        return true;
    } 
    
    if(item->getData() < value && item->m_left != nullptr)
    {
        tmp = removePrivate(value, item->m_left);
    }
    else if(item->getData() > value && item->m_right !=nullptr)
    {
        tmp = removePrivate(value, item->m_right);
    }
    return tmp;
}

std::shared_ptr<Item> Nevyvazeny::leftEndFrom(std::shared_ptr<Item> item)
{
    if (item->m_left == nullptr)
    {
        return item;
    }
    return leftEndFrom(item->m_left);
}

void Nevyvazeny::addPr(int value, std::shared_ptr<Item> item)
{
    // value > item->value  ide do lava    
    if(item->getData() < value)
    {
        if(item->m_left == nullptr)
        {
            item->m_left = std::make_shared<Item>(value, m_head);
            return;
        }
        addPr(value,item->m_left);
        
    }
    else
    {
        if(item->m_right == nullptr)
        {
            item->m_right = std::make_shared<Item>(value, m_head);
            return;
        }
        addPr(value,item->m_right);  
    }
};