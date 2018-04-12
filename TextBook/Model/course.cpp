#include "course.h"

Course::Course(ContentPart * parent)
    : ContentPart(parent)
{
    m_filePath = "";
}

QString Course::progressPath() const
{
    QString result = m_filePath;
    result.remove(result.lastIndexOf(".xml", -1, Qt::CaseInsensitive), 4);
    result.append(".dat");
    return result;
}
