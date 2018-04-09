#ifndef XMLIMPORTER_H
#define XMLIMPORTER_H
#include <QString>
#include <QXmlStreamReader>
#include "Model/contentpart.h"
#include "Model/contentmodel.h"
#include "Model/lecture.h"
#include "Model/slide.h"
#include "Model/quiz.h"
#include "Model/question.h"

class XmlContentImporter
{
public:
    XmlContentImporter();

    bool importCourse(ContentModel *model, QString filePath);

private:
    QXmlStreamReader m_reader;
    void importLecture(ContentPart *course);
    void importSlide(Lecture *lecture);
    void importQuiz(Lecture *lecture);
    void importQuestion(Quiz *quiz);
};

#endif // XMLIMPORTER_H
