#ifndef SLIDE_H
#define SLIDE_H
#include <QString>
#include "textbookitem.h"

class Slide : public TextbookItem
{
public:
    Slide();

    QString imageFileName() const;
    void setImageFileName(const QString &value);

private:
    QString m_imageFileName;
};

#endif // SLIDE_H
