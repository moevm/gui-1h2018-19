#include "contentmodel.h"
#include "course.h"
#include <QFile>

ContentModel::ContentModel()
    : ContentPart(Q_NULLPTR)
{

}

void ContentModel::saveProgress()
{
    foreach (ContentItem *item, items()) {
        Course *course = dynamic_cast<Course*>(item);
        if (course != Q_NULLPTR) {
            QHash<QString, float> progressHash;
            course->collectProgress(progressHash);
            if (!progressHash.isEmpty()) {
                QFile file(course->progressPath());
                if (file.open(QIODevice::WriteOnly)) {
                    QDataStream out(&file);
                    out << progressHash;
                    file.close();
                }
            }
        }
    }
}
