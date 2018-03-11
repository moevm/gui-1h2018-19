#ifndef LECTURE_H
#define LECTURE_H
#include <QList>
#include "textbookitem.h"
#include "slide.h"

class Lecture : public TextbookItem, public QList<Slide*>
{
public:
    Lecture();
    ~Lecture();

    int selectedIndex() const;
    void setSelectedIndex(int value);

private:
    int m_selectedIndex;
};

#endif // LECTURE_H
