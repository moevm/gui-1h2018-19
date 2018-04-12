#include "quiz.h"
#include "lecture.h"

Quiz::Quiz(Lecture *parent)
    : ContentPart(Q_NULLPTR)
{
    setParent(parent);
    parent->m_quiz = this;
}

bool Quiz::canForward() const
{
    if (items().count() == 0)
        return false;
    return selectedIndex() >= 0 && selectedIndex() < items().count();
}
