//#include <Vyvazeny.h>
#include "../include/Vyvazeny.h"

Vyvazeny::Vyvazeny()
{
}

Vyvazeny::Vyvazeny(int value)
{
    m_head = std::make_shared<Item>(value, nullptr);
}

Vyvazeny::~Vyvazeny()
{
}

std::shared_ptr<Item> Vyvazeny::rr_Rotation(std::shared_ptr<Item> item_root)
{
    auto ptr = item_root->m_right;
    item_root->m_right = ptr->m_left;
    ptr->m_left = item_root;
    if (item_root == m_head)
    {
        m_head = ptr;
    }
    return ptr;
}

std::shared_ptr<Item> Vyvazeny::ll_Rotation(std::shared_ptr<Item> item_root)
{
    auto ptr = item_root->m_left;
    item_root->m_left = ptr->m_right;
    ptr->m_right = item_root;
    if (item_root == m_head)
    {
        m_head = ptr;
    }
    return ptr;
}
std::shared_ptr<Item> Vyvazeny::lr_Rotation(std::shared_ptr<Item> item_root)
{
    item_root->m_left = rr_Rotation(item_root->m_left);
    if (item_root == m_head)
    {
        m_head = ll_Rotation(item_root);
    }
    else
    {
        item_root = ll_Rotation(item_root);
    }
    return item_root;
}

std::shared_ptr<Item> Vyvazeny::rl_Rotation(std::shared_ptr<Item> item_root)
{
    item_root->m_right = ll_Rotation(item_root->m_right);
    if (item_root == m_head)
    {
        m_head = rr_Rotation(item_root);
    }
    else
    {
        item_root = rr_Rotation(item_root);
    }
    return item_root;
}

void Vyvazeny::balance(std::shared_ptr<Item> item)
{
    int tmp_difrent = diferent(item);
    if (tmp_difrent > 1)
    {
        tmp_difrent = diferent(item->m_left);
        if (tmp_difrent > 0)
        {
            item = ll_Rotation(item);
        }
        else
        {
            lr_Rotation(item);
        }
    }
    else if (tmp_difrent < -1)
    {
        tmp_difrent = diferent(item->m_right);
        if (tmp_difrent > 0)
        {
            rl_Rotation(item);
        }
        else
        {
            item = rr_Rotation(item);
        }
    }
}

int Vyvazeny::height(std::shared_ptr<Item> item)
{
    int tmp = 0;
    if (item != nullptr)
    {
        int l_height = height(item->m_left);
        int r_height = height(item->m_right);
        tmp = std::max(l_height, r_height);
    }
    return ++tmp;
}

int Vyvazeny::diferent(std::shared_ptr<Item> item)
{
    int l_height = height(item->m_left);
    int r_height = height(item->m_right);
    return l_height - r_height;
}

void Vyvazeny::add(int value)
{
    if (m_head == nullptr)
    {
        m_head = std::make_shared<Item>(value, nullptr);
    }
    else
    {
        addPr(value, m_head);
        balance(m_head);
    }
}

bool Vyvazeny::remove(int value)
{
    bool tmp = removePrivate(value, m_head);
    balance(m_head);
    return tmp;
}

void Vyvazeny::add(std::shared_ptr<Item> newItem)
{
    if (m_head == nullptr)
    {
        m_head = std::make_shared<Item>(*newItem.get());
    }
    else
    {
        addPr(newItem, m_head);
        balance(m_head);
    }
}