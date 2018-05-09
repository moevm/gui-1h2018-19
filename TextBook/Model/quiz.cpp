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

int Quiz::correctAnswersCount() const
{
    int result = 0;
    foreach(ContentItem* item, items()) {
        if (item->progress() == 1.0f)
            result++;
    }
    return result;
}

float Quiz::averageMark() const
{
    int count = items().count();
    if (count == 0)
        return 0.0f;
    return 5.0 * correctAnswersCount() / count;
}
