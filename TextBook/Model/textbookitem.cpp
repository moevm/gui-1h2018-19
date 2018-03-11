#include "textbookitem.h"

TextbookItem::TextbookItem()
{
    _name = "";
    _description = "";
}

QString TextbookItem::name() const
{
    return _name;
}

void TextbookItem::setName(QString value)
{
    _name = value;
}

QString TextbookItem::description() const
{
    return _description;
}

void TextbookItem::setDescription(QString value)
{
    _description = value;
}

