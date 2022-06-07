#include <Item.h>

Item::Item(int val, std::shared_ptr<Item> parent):value(val),m_parent(parent)
{
    
}

Item::~Item()
{

}