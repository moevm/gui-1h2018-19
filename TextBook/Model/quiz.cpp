#include "quiz.h"
#include "lecture.h"

Quiz::Quiz(Lecture *parent)
    : ContentPart(Q_NULLPTR)
{
    setParent(parent);
    parent->m_quiz = this;
}
