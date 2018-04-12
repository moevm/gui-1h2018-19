#include "contentitem.h"
#include "contentpart.h"

ContentItem::ContentItem(ContentPart *parent)
{
    m_id = "";
    m_name = "";
    m_description = "";
    m_parent = parent;
    if (m_parent != Q_NULLPTR)
        m_parent->m_items.append(this);
}

ContentItem::~ContentItem()
{
    m_parent = Q_NULLPTR;
}
