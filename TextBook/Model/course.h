#ifndef COURSE_H
#define COURSE_H
#include "contentpart.h"

class Course : public ContentPart
{
public:
    Course(ContentPart * parent);

    QString filePath() const { return m_filePath; }
    void setFilePath(const QString &value) { m_filePath = value; }

    QString progressPath() const;

private:
    QString m_filePath;
};

#endif // COURSE_H
