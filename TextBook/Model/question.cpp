#include "question.h"

Question::Question(ContentPart *parent)
    : ContentItem(parent)
{
    m_selectedAnswerIndex = -1;
    m_correctAnswerIndex = -2;
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
