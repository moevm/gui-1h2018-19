#ifndef QUIZ_H
#define QUIZ_H
#include "contentpart.h"

class Quiz : public ContentPart
{
public:
    Quiz(ContentPart *parent);

    ContentViewType viewType() const { return ContentViewType::QuizView; }
};

#endif // QUIZ_H
