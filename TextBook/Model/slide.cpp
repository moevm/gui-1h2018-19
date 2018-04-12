#include "slide.h"

Slide::Slide(ContentPart *parent)
    : ContentItem(parent)
{
    m_imagePath = "";
    m_progress = 0.0f;
}

void Slide::setProgress(float value)
{
    if (value < 0.0f)
        value = 0.0f;
    if (value > 1.0f)
        value = 1.0f;
    m_progress = value;
}

void Slide::collectProgress(QHash<QString, float> &progressHash)
{
    if (m_progress > 0.0f && !id().isEmpty())
        progressHash[id()] = m_progress;
}
