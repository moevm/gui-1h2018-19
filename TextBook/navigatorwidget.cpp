#include "navigatorwidget.h"
#include <QPainter>
#define INDICATOR_SIZE 25

NavigatorWidget::NavigatorWidget(QWidget *parent) : QWidget(parent)
{
    m_selectedIndex = -1;
}

void NavigatorWidget::setSize(int value)
{
    if (value < 0)
        value = 0;
    if (m_items.size() == value)
        return;
    m_items.clear();
    if (value > 0)
        m_items.fill(0.0f, value);
    if (m_selectedIndex >= m_items.size())
        m_selectedIndex = m_items.size() - 1;
    update();
}

void NavigatorWidget::setValue(int index, float value) {
    m_items.replace(index, value);
    update();
}

void NavigatorWidget::setSelectedIndex(int value)
{
    if (value < 0)
        m_selectedIndex = -1;
    else if (value >= m_items.size())
        m_selectedIndex = m_items.size() - 1;
    else
        m_selectedIndex = value;
    update();
}

void NavigatorWidget::paintEvent(QPaintEvent*)
{
    QColor color(178, 0, 255);
    QBrush brush(color);
    QPen pen(color);
    QPainter painter(this);
    painter.setBrush(Qt::NoBrush);
    QRect clientRect = rect();
    for (int i = 0; i < m_items.size(); i++) {
        float progress = m_items.at(i);
        if (progress > 0.0f) {
            QRectF fr(INDICATOR_SIZE * i + 3,
                    (clientRect.height() - (INDICATOR_SIZE - 3)) / 2,
                    (INDICATOR_SIZE - 5) * qMax(progress, 0.5f), INDICATOR_SIZE - 3);
            painter.fillRect(fr, brush);
        }
        if (i == m_selectedIndex) {
            painter.setPen(pen);
            QRectF br(INDICATOR_SIZE * i + 1,
                      (clientRect.height() - INDICATOR_SIZE) / 2,
                      INDICATOR_SIZE - 2, INDICATOR_SIZE);
            painter.drawRect(br);
        }
        else {
            painter.setPen(Qt::darkGray);
            QRectF br(INDICATOR_SIZE * i + 3,
                    (clientRect.height() - (INDICATOR_SIZE - 3)) / 2,
                    (INDICATOR_SIZE - 5), INDICATOR_SIZE - 3);
            painter.drawRect(br);
        }
    }
}

void NavigatorWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::MouseButton::LeftButton)
        return;
    int position = event->x() / INDICATOR_SIZE;
    if (position >= size())
        return;
    if (position != m_selectedIndex) {
        setSelectedIndex(position);
        emit selectedIndexChanged();
    }
}


