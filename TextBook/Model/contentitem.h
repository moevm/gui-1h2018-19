#ifndef CONTENTITEM_H
#define CONTENTITEM_H
#include <QString>

class ContentPart;

class ContentItem
{
public:
    ContentItem(ContentPart *parent);
    virtual ~ContentItem();

    ContentPart *parent() const { return m_parent; }

    QString name() const { return m_name; }
    void setName(const QString &value) { m_name = value; }

    QString description() const { return m_description; }
    void setDescription(const QString &value) { m_description = value; }

protected:
    void setParent(ContentPart *parent) { m_parent = parent; }

private:
    ContentPart *m_parent;
    QString m_name;
    QString m_description;
};

#endif // CONTENTITEM_H
