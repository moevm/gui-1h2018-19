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

    ContentPart *course = Q_NULLPTR;

    m_reader.setDevice(&file);

    while (!m_reader.atEnd() && !m_reader.hasError()) {
        m_reader.readNext();
        if (m_reader.tokenType() == QXmlStreamReader::StartElement) {
            if (course == Q_NULLPTR) {
                if (m_reader.name() == "course")
                    course = new ContentPart(model);
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
            if (m_reader.name() == "name")
                slide->setName(m_reader.readElementText());
            else if (m_reader.name() == "description")
                slide->setDescription(m_reader.readElementText());
            else if (m_reader.name() == "image")
                slide->setImagePath(m_reader.readElementText());
        }
        m_reader.readNext();
    }
}
