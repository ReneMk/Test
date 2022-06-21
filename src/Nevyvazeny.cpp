#include "../include/Nevyvazeny.h"

Nevyvazeny::Nevyvazeny()
{
}

Nevyvazeny::Nevyvazeny(int value) //: m_head(std::make_shared<Item>(value,nullptr))
{
    m_head = (std::make_shared<Item>(value, nullptr));
}

Nevyvazeny::~Nevyvazeny()
{
    removeTree();
}

void Nevyvazeny::add(int value)
{
    addPr(value, m_head);
}

void Nevyvazeny::add(std::shared_ptr<Item> newItem)
{
    if (m_head == nullptr)
    {
        m_head = std::make_shared<Item>(*newItem.get());
    }
    else
    {
        addPr(newItem, m_head);
    }
}

bool Nevyvazeny::remove(int value)
{
    return removePrivate(value, m_head);
}