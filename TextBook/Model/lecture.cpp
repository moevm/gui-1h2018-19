#include "lecture.h"

Lecture::Lecture()
    :TextbookItem(), QList<Slide*>()
{
    m_selectedIndex = -1;
}

Lecture::~Lecture()
{
    foreach(Slide* item, this)
        delete item;
    clear();
}

int Lecture::selectedIndex() const
{
    return m_selectedIndex;
}

void Lecture::setSelectedIndex(int value)
{
    if (value < 0)
        value = -1;
    if (value > count())
        value = count() - 1;
    m_selectedIndex = value;
}
