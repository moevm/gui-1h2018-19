#ifndef LECTURE_H
#define LECTURE_H
#include "contentpart.h"

class Lecture : public ContentPart
{
public:
    Lecture(ContentPart *parent);

    ContentViewType viewType() const { return ContentViewType::SlideView; }
};

#endif // LECTURE_H
