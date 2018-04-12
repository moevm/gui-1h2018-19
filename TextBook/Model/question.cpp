#include "question.h"

Question::Question(ContentPart *parent)
    : ContentItem(parent)
{
    m_selectedAnswerIndex = -1;
    m_correctAnswerIndex = -2;
    m_progress = 0.0f;
}

void Question::setSelectedAnswerIndex(int value)
{
    if (value >= m_answers.count())
        value = m_answers.count() - 1;
    if (value < 0)
        value = -1;
    m_selectedAnswerIndex = value;
}

void Question::setCorrectAnswerIndex(int value)
{
    if (value >= m_answers.count())
        value = m_answers.count() - 1;
    if (value < 0)
        value = -2;
    m_correctAnswerIndex = value;
}

void Question::setProgress(float value)
{
    if (value < 0.0f)
        value = 0.0f;
    if (value > 1.0f)
        value = 1.0f;
    m_progress = value;
}

void Question::collectProgress(QHash<QString, float> &progressHash)
{
    if (m_progress > 0.0f && !id().isEmpty())
        progressHash[id()] = m_progress;
}
