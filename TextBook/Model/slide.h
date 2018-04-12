#ifndef SLIDE_H
#define SLIDE_H
#include <QString>
#include "contentitem.h"
#include "contentpart.h"

class Slide : public ContentItem
{
public:
    Slide(ContentPart *parent);

    ContentViewType viewType() const { return ContentViewType::SlideView; }

    bool canForward() const;
    bool canBackward() const;
    bool canLevelUp() const;

    QString imagePath() const { return m_imagePath; }
    void setImagePath(const QString &value) { m_imagePath = value; }

    float progress() const { return m_progress; }
    void setProgress(float value);
    void collectProgress(QHash<QString, float> &progressHash);

private:
    QString m_imagePath;
    float m_progress;
};

#endif // SLIDE_H
