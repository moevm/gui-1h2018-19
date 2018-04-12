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

float Lecture::progress() const
{
    float result = ContentPart::progress();
    if (m_quiz != Q_NULLPTR) {
        int slideCount = items().count();
        int quizCount = m_quiz->items().count();
        result = (result * slideCount + m_quiz->progress() * quizCount);
        int count = slideCount + quizCount;
        if (count > 1)
            result /= count;
    }
    return result;
}

void Lecture::collectProgress(QHash<QString, float> &progressHash)
{
    ContentPart::collectProgress(progressHash);
    if (m_quiz != Q_NULLPTR)
        m_quiz->collectProgress(progressHash);
}
