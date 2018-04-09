#ifndef QUIZ_H
#define QUIZ_H
#include "contentpart.h"

class Lecture;

class Quiz : public ContentPart
{
public:
    Quiz(Lecture *parent);

    ContentViewType viewType() const { return ContentViewType::QuizView; }
};

#endif // QUIZ_H
