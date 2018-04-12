#ifndef QUESTION_H
#define QUESTION_H
#include <QStringList>
#include "contentitem.h"
#include "contentpart.h"

class Question : public ContentItem
{
public:
    Question(ContentPart * parent);

    ContentViewType viewType() const { return ContentViewType::QuizView; }

    QStringList &answers() { return m_answers; }

    int selectedAnswerIndex() const { return m_selectedAnswerIndex; }
    int correctAnswerIndex() const { return m_correctAnswerIndex; }

    void setSelectedAnswerIndex(int value);
    void setCorrectAnswerIndex(int value);

    float progress() const { return m_progress; }
    void setProgress(float value);
    void collectProgress(QHash<QString, float> &progressHash);

private:
    QStringList m_answers;
    int m_selectedAnswerIndex;
    int m_correctAnswerIndex;
    float m_progress;
};

#endif // QUESTION_H
