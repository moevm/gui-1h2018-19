#ifndef QUIZ_H
#define QUIZ_H
#include "contentpart.h"

class Lecture;

class Quiz : public ContentPart
{
public:
    Quiz(Lecture *parent);

    ContentViewType viewType() const { return ContentViewType::QuizView; }
    bool canForward() const;

    int correctAnswersCount() const;
    float averageMark() const;
};

#endif // QUIZ_H
