#ifndef CONTENTITEM_H
#define CONTENTITEM_H
#include <QString>
#include <QHash>

class ContentPart;

class ContentItem
{
public:
    ContentItem(ContentPart *parent);
    virtual ~ContentItem();

    ContentPart *parent() const { return m_parent; }

    QString id() const { return m_id; }
    void setId(const QString &value) { m_id = value; }

    QString name() const { return m_name; }
    void setName(const QString &value) { m_name = value; }

    QString description() const { return m_description; }
    void setDescription(const QString &value) { m_description = value; }

    virtual float progress() const = 0;
    virtual void setProgress(float value) = 0;
    virtual void collectProgress(QHash<QString, float> &progressHash) = 0;

protected:
    void setParent(ContentPart *parent) { m_parent = parent; }

private:
    ContentPart *m_parent;
    QString m_id;
    QString m_name;
    QString m_description;
};

#endif // CONTENTITEM_H
