#include "contentpart.h"

ContentPart::ContentPart(ContentPart *parent)
    : ContentItem(parent)
{
    m_selectedIndex = -1;
}

ContentPart::~ContentPart()
{
    clear();
}

void ContentPart::setSelectedIndex(int index)
{
    if (index < 0)
        index = 0;
    if (index >= m_items.count())
        index = m_items.count() - 1;
    m_selectedIndex = index;
}

ContentItem *ContentPart::selectedItem() const
{
    if (m_selectedIndex < 0)
        return Q_NULLPTR;
    return m_items.at(m_selectedIndex);
}

bool ContentPart::canForward() const
{
    if (viewType() == ContentViewType::SlideView || viewType() == ContentViewType::QuizView)
        return m_selectedIndex >= 0 && m_selectedIndex < (m_items.count() - 1);
    return selectedItem() != Q_NULLPTR;
}

bool ContentPart::canBackward() const
{
    if (viewType() == ContentViewType::SlideView || viewType() == ContentViewType::QuizView)
        return m_selectedIndex > 0;
    return false;
}

bool ContentPart::canLevelUp() const
{
    return parent() != Q_NULLPTR;
}

bool ContentPart::canQuiz() const
{
    return false;
}

void ContentPart::reset()
{
    m_selectedIndex = -1;
}

void ContentPart::forward()
{
    if (m_selectedIndex < (m_items.count() - 1))
        m_selectedIndex++;
}

void ContentPart::backward()
{
    if (m_selectedIndex > 0)
        m_selectedIndex--;
}

void ContentPart::clear()
{
    while (!m_items.isEmpty())
        delete m_items.takeFirst();
    reset();
}

float ContentPart::progress() const
{
    float result = 0.0f;
    int count = m_items.count();
    for (int i = 0; i < count; i++)
        result += m_items[i]->progress();
    if (count > 1)
        result /= count;
    return result;
}

void ContentPart::collectProgress(QHash<QString, float> &progressHash)
{
    int count = m_items.count();
    for (int i = 0; i < count; i++)
        m_items[i]->collectProgress(progressHash);
}
