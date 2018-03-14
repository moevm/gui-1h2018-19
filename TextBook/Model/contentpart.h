#ifndef CONTENTPART_H
#define CONTENTPART_H
#include <QList>
#include "contentitem.h"

class ContentPart : public ContentItem
{
    friend class ContentItem;

public:
    ContentPart(ContentPart *parent);
    ~ContentPart();

    const QList<ContentItem *> &items() const { return m_items; }

    int selectedIndex() const { return m_selectedIndex; }
    ContentItem* selectedItem() const;

    void reset();
    void forward();
    void backward();
    void clear();

private:
    QList<ContentItem *> m_items;
    int m_selectedIndex;
};

#endif // CONTENTPART_H
