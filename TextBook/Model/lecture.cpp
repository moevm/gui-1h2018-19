#include "lecture.h"

Lecture::Lecture(ContentPart *parent)
    : ContentPart(parent)
{
    m_quiz = Q_NULLPTR;
}

Lecture::~Lecture()
{
    if (m_quiz != Q_NULLPTR) {
        delete m_quiz;
        m_quiz = Q_NULLPTR;
    }
}

bool Lecture::canQuiz() const
{
    return m_quiz != Q_NULLPTR && canBackward() && !canForward();
}
