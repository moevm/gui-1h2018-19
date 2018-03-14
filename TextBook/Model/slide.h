#ifndef SLIDE_H
#define SLIDE_H
#include <QString>
#include "contentitem.h"
#include "contentpart.h"

class Slide : public ContentItem
{
public:
    Slide(ContentPart *parent);

    QString imagePath() const { return m_imagePath; }
    void setImagePath(const QString &value) { m_imagePath = value; }

private:
    QString m_imagePath;
};

#endif // SLIDE_H
