#ifndef CONTENTMODEL_H
#define CONTENTMODEL_H
#include "contentpart.h"

class ContentModel : public ContentPart
{
public:
    ContentModel();

    void saveProgress();
};

#endif // CONTENTMODEL_H
