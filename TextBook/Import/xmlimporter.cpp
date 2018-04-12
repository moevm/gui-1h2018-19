#include "xmlimporter.h"
#include <QFile>
#include <QDebug>

XmlContentImporter::XmlContentImporter()
{

}

bool XmlContentImporter::importCourse(ContentModel *model, QString filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    Course *course = Q_NULLPTR;

    m_reader.setDevice(&file);

    while (!m_reader.atEnd() && !m_reader.hasError()) {
        m_reader.readNext();
        if (m_reader.tokenType() == QXmlStreamReader::StartElement) {
            if (course == Q_NULLPTR) {
                if (m_reader.name() == "course") {
                    course = new Course(model);
                    course->setFilePath(filePath);
                    loadProgressHash(course->progressPath());
                }
            }
            else {
                if (m_reader.name() == "name")
                    course->setName(m_reader.readElementText());
                else if (m_reader.name() == "description")
                    course->setDescription(m_reader.readElementText());
                else if (m_reader.name() == "lecture")
                    importLecture(course);
            }
        }
    }

    bool success = !m_reader.hasError();
    m_reader.clear();
    file.close();
    return success;
}

void XmlContentImporter::loadProgressHash(QString filePath)
{
    m_progressHash.clear();
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        in >> m_progressHash;
        file.close();
    }
}

void XmlContentImporter::importLecture(ContentPart * course)
{
    Lecture* lecture = new Lecture(course);
    m_reader.readNext();
    while (!m_reader.hasError() &&
           !(m_reader.tokenType() == QXmlStreamReader::EndElement && m_reader.name() == "lecture")) {
        if (m_reader.tokenType() == QXmlStreamReader::StartElement) {
            if (m_reader.name() == "name")
                lecture->setName(m_reader.readElementText());
            else if (m_reader.name() == "description")
                lecture->setDescription(m_reader.readElementText());
            else if (m_reader.name() == "slide")
                importSlide(lecture);
            else if (m_reader.name() == "quiz")
                importQuiz(lecture);
        }
        m_reader.readNext();
    }
}

void XmlContentImporter::importSlide(Lecture *lecture)
{
    Slide* slide = new Slide(lecture);
    m_reader.readNext();
    while (!m_reader.hasError() &&
           !(m_reader.tokenType() == QXmlStreamReader::EndElement && m_reader.name() == "slide")) {
        if (m_reader.tokenType() == QXmlStreamReader::StartElement) {
            if (m_reader.name() == "id")
                slide->setId(m_reader.readElementText());
            else if (m_reader.name() == "name")
                slide->setName(m_reader.readElementText());
            else if (m_reader.name() == "description")
                slide->setDescription(m_reader.readElementText());
            else if (m_reader.name() == "image")
                slide->setImagePath(m_reader.readElementText());
        }
        m_reader.readNext();
    }
    if (m_progressHash.contains(slide->id()))
        slide->setProgress(m_progressHash[slide->id()]);
}

void XmlContentImporter::importQuiz(Lecture *lecture)
{
    Quiz* quiz = new Quiz(lecture);
    m_reader.readNext();
    while (!m_reader.hasError() &&
           !(m_reader.tokenType() == QXmlStreamReader::EndElement && m_reader.name() == "quiz")) {
        if (m_reader.tokenType() == QXmlStreamReader::StartElement) {
            if (m_reader.name() == "name")
                quiz->setName(m_reader.readElementText());
            else if (m_reader.name() == "description")
                quiz->setDescription(m_reader.readElementText());
            else if (m_reader.name() == "question")
                importQuestion(quiz);
        }
        m_reader.readNext();
    }
}

void XmlContentImporter::importQuestion(Quiz *quiz)
{
    Question* question = new Question(quiz);
    m_reader.readNext();
    while (!m_reader.hasError() &&
           !(m_reader.tokenType() == QXmlStreamReader::EndElement && m_reader.name() == "question")) {
        if (m_reader.tokenType() == QXmlStreamReader::StartElement) {
            if (m_reader.name() == "id")
                question->setId(m_reader.readElementText());
            else if (m_reader.name() == "name")
                question->setName(m_reader.readElementText());
            else if (m_reader.name() == "description")
                question->setDescription(m_reader.readElementText());
            else if (m_reader.name() == "answer")
                question->answers().append(m_reader.readElementText());
            else if (m_reader.name() == "correctAnswer") {
                question->answers().append(m_reader.readElementText());
                question->setCorrectAnswerIndex(question->answers().count() - 1);
            }
        }
        m_reader.readNext();
    }
    if (m_progressHash.contains(question->id()))
        question->setProgress(m_progressHash[question->id()]);
}
