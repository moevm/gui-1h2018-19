#ifndef CONTENTPART_H
#define CONTENTPART_H
#include <QList>
#include "contentitem.h"

enum ContentViewType {
    SelectorView,
    SlideView,
    QuizView
};

class ContentPart : public ContentItem
{
    friend class ContentItem;

public:
    ContentPart(ContentPart *parent);
    ~ContentPart();

    virtual ContentViewType viewType() const { return ContentViewType::SelectorView; }

    const QList<ContentItem *> &items() const { return m_items; }

    int selectedIndex() const { return m_selectedIndex; }
    void setSelectedIndex(int index);

    ContentItem* selectedItem() const;

    bool canForward() const;
    bool canBackward() const;
    bool canLevelUp() const;
    virtual bool canQuiz() const;

    void reset();
    void forward();
    void backward();
    void clear();

private:
    QList<ContentItem *> m_items;
    int m_selectedIndex;
};

#endif // CONTENTPART_H
