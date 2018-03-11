#include "slide.h"

Slide::Slide()
    : TextbookItem()
{
    m_imageFileName = "";
}

QString Slide::imageFileName() const
{
    return m_imageFileName;
}

void Slide::setImageFileName(const QString &value)
{
    m_imageFileName = value;
}
