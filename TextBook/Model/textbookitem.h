#ifndef TEXTBOOKITEM_H
#define TEXTBOOKITEM_H
#include <QString>

class TextbookItem
{
protected:
    TextbookItem();

public:
    QString name() const;
    void setName(QString value);

    QString description() const;
    void setDescription(QString value);

private:
    QString _name;
    QString _description;
};

#endif // TEXTBOOKITEM_H
