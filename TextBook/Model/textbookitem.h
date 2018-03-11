#ifndef TEXTBOOKITEM_H
#define TEXTBOOKITEM_H
#include <QString>

class TextbookItem
{
protected:
    TextbookItem();

public:
    virtual ~TextbookItem();

    QString name() const;
    void setName(const QString &value);

    QString description() const;
    void setDescription(const QString &value);

private:
    QString m_name;
    QString m_description;
};

#endif // TEXTBOOKITEM_H
