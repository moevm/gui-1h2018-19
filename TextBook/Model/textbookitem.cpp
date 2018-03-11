#include "textbookitem.h"

TextbookItem::TextbookItem()
{
    m_name = "";
    m_description = "";
}

TextbookItem::~TextbookItem()
{
    // do nothing
}

QString TextbookItem::name() const
{
    return m_name;
}

void TextbookItem::setName(const QString &value)
{
    m_name = value;
}

QString TextbookItem::description() const
{
    return m_description;
}

void TextbookItem::setDescription(const QString &value)
{
    m_description = value;
}

