#ifndef LECTURE_H
#define LECTURE_H
#include "contentpart.h"
#include "quiz.h"

class Lecture : public ContentPart
{
    friend class Quiz;

public:
    Lecture(ContentPart *parent);
    ~Lecture();

    ContentViewType viewType() const { return ContentViewType::SlideView; }

    bool canQuiz() const;

    Quiz *quiz() { return m_quiz; }

    float progress() const;
    void collectProgress(QHash<QString, float> &progressHash);

private:
    Quiz *m_quiz;
};

#endif // LECTURE_H
