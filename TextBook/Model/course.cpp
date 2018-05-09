#include "course.h"
#include "lecture.h"

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

float Course::averageMark() const
{
    int count = 0;
    float result = 0.0f;
    foreach(ContentItem* item, items()) {
        Lecture* lecture = dynamic_cast<Lecture*>(item);
        if (lecture != Q_NULLPTR) {
            Quiz* quiz = lecture->quiz();
            if (quiz != Q_NULLPTR) {
                count++;
                result += quiz->averageMark();
            }
        }
    }
    if (count == 0)
        return 0.0f;
    return result / count;
}
