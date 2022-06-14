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
    if (value == item->getData())
    {
        return item;
    }
    std::shared_ptr<Item> ptr;
    if (value > item->getData())
    {
        ptr = findPrivate(value, item->m_left);
    }
    else
    {
        ptr = findPrivate(value, item->m_right);
    }
    return ptr;
}

void IBinaryTree::printTreePrivate(std::shared_ptr<Item> item)
{
    if (item == nullptr)
        return;
    printTreePrivate(item->m_right);
    item->printData();
    std::cout << " ";
    printTreePrivate(item->m_left);
}

void IBinaryTree::addPr(int value, std::shared_ptr<Item> memberOfTree)
{
    // value > item->value  ide do lava
    if (memberOfTree->getData() < value)
    {
        if (memberOfTree->m_left == nullptr)
        {
            memberOfTree->m_left = std::make_shared<Item>(value, m_head);
            return;
        }
        addPr(value, memberOfTree->m_left);
    }
    else
    {
        if (memberOfTree->m_right == nullptr)
        {
            memberOfTree->m_right = std::make_shared<Item>(value, m_head);
            return;
        }
        addPr(value, memberOfTree->m_right);
    }
}

void IBinaryTree::addPr(std::shared_ptr<Item> newItem, std::shared_ptr<Item> memberOfTree)
{
    // value > item->value  ide do lava
    if (memberOfTree->getData() < newItem->getData())
    {
        if (memberOfTree->m_left == nullptr)
        {
            memberOfTree->m_left = std::make_shared<Item>(*newItem.get());
            return;
        }
        addPr(newItem, memberOfTree->m_left);
    }
    else
    {
        if (memberOfTree->m_right == nullptr)
        {
            memberOfTree->m_right = std::make_shared<Item>(*newItem.get());
            return;
        }
        addPr(newItem, memberOfTree->m_right);
    }
}

std::shared_ptr<Item> IBinaryTree::leftEndFrom(std::shared_ptr<Item> item)
{
    if (item->m_left == nullptr)
    {
        return item;
    }
    return leftEndFrom(item->m_left);
}

void IBinaryTree::changeHead()
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

bool IBinaryTree::removePrivate(int value, std::shared_ptr<Item> item)
{
    if (item == m_head)
    {
        changeHead();
        return true;
    }

    if (item == nullptr || (item->m_left == nullptr && item->m_right == nullptr))
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
        return true;
    }

    if (item->getData() < value && item->m_left != nullptr)
    {
        tmp = removePrivate(value, item->m_left);
    }
    else if (item->getData() > value && item->m_right != nullptr)
    {
        tmp = removePrivate(value, item->m_right);
    }
    return tmp;
}

void IBinaryTree::printHead()
{
    std::cout << "Head: " << m_head->getData() << std::endl;
}