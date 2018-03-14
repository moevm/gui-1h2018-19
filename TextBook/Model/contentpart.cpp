#include "contentpart.h"

ContentPart::ContentPart(ContentPart *parent)
    : ContentItem(parent)
{
    m_selectedIndex = -1;
}

ContentPart::~ContentPart()
{
    clear();
}

ContentItem *ContentPart::selectedItem() const
{
    if (m_selectedIndex < 0)
        return Q_NULLPTR;
    return m_items.at(m_selectedIndex);
}

void ContentPart::reset()
{
    m_selectedIndex = -1;
}

void ContentPart::forward()
{
    if (m_selectedIndex < (m_items.count() - 1))
        m_selectedIndex++;
}

void ContentPart::backward()
{
    if (m_selectedIndex > 0)
        m_selectedIndex--;
}

void ContentPart::clear()
{
    while (!m_items.isEmpty())
        delete m_items.takeFirst();
    reset();
}
